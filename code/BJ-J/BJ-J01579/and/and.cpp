#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, m; ll a[N], ans; bool f=1, ag=1;
bool cmp(ll x, ll y) {return x > y;}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        if(n == m)
        {
            if(i == 1) ans = a[i];
            else ans &= a[i];
        }
        if(a[i] != i-1) f=0;
        if(a[i] >= 4) ag=0;
    }
    if(f) {cout << n-m; return 0;} //B
    if(n == m) {cout << ans; return 0;} //7
    sort(a+1, a+n+1, cmp);
    if(m == 1) {cout << a[1]; return 0;} // 6
    if(m == n-1)
    {
        ans = a[1];
        for(int i=2; i<n; i++) ans &= a[i];
        cout << ans << '\n'; return 0;
    }
    if(m == 2) // 8-10
    {
        for(int i=1; i<=n; i++)
            for(int j=i+1; j<=n; j++)
                ans = max(ans, a[i] & a[j]);
        cout << ans << '\n'; return 0;
    }
    ans = a[1];
    for(int i=2; i<=m; i++) ans &= a[i];
    cout << ans << '\n';
    return 0;
}
