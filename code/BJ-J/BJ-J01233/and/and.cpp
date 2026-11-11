#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    freopen("and.in", "r" , stdin);
    freopen("and.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> v[i];
    sort(v.begin(), v.end(), cmp);
    if(m == 1)
    {
        ll MAX = 0;
        for(int i = 1; i <= n; i ++)
            MAX = max(MAX, v[i]);
        cout << MAX;
    }
    else if(m == n)
    {
        int A = 32 * 32 * 32 * 32 * 32 * 32;
        for(int i = 1; i <= n; i ++)
            A = A & v[i];
        cout << A;
    }
    fclose(stdin);
    fclose(stdout);
}
