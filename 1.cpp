// Dadaji ka code h bete kaam to karega hiiii

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
#define pb push_back;
typedef pair<int, int> pii;
#define no cout << "NO";
#define yes cout << "YES";
#define endl '\n'
#define mod 1000000007
#define inf INT_MAX
#define loop(i, s, l, j) for (int i = s; i < l; i += j)
ll gcd(ll a, ll b) //(a > b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll power(ll a, ll b)
{
    if (b == 0)
        return 1;

    ll t = power(a, b / 2);
    if (b % 2 == 0)
    {
        return (t * t) % mod;
    }
    else
    {
        return (t * t * a) % mod;
    }
}
vector<bool> sieve(long long n) // no of primes till n (included)
{
    ll count = 0;
    vector<bool> primes(n + 1, true);

    primes[0] = primes[1] = false;
    for (long long i = 2; i <= n; i++)
    {

        if (primes[i])
        {
            count++;
            for (long long j = i * i; j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }
    return primes;
}
void merge(vector<int> &arr, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
vector<vector<int>> dirs = {{1, -1}, {-1, -1}, {-1, 1}, {1, 1}};
void solve()
{
    ll a, b;
    cin >> a >> b; // knight's moves
    ll kpos1, kpos2;
    cin >> kpos1 >> kpos2;
    ll qpos1, qpos2;
    cin >> qpos1 >> qpos2;

    set<pair<int, int>> king, queen;
    for (auto it : dirs)
    {
        king.insert({kpos1 + it[0] * a, kpos2 + it[1] * b});
        king.insert({kpos1 + it[0] * b, kpos2 + it[1] * a});
        queen.insert({qpos1 + it[0] * a, qpos2 + it[1] * b});
        queen.insert({qpos1 + it[0] * b, qpos2 + it[1] * a});
    }
    int ans = 0;
    for (auto it : king)
    {
        if (queen.find(it) != queen.end())
        {
            ans++;
        }
    }
    cout << ans;
    return;
}
int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}