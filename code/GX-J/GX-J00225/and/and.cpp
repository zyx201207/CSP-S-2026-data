#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void svb(), sv1(), svn(), svnl1();
void fre()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("and.in","r", stdin);
    freopen("and.out","w",stdout);
}
ll a[11451419];
ll n, m;
signed main()
{
    fre();

    
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];

    if (n <= 20) svb();
    if (m == 1) sv1();
    if (m == n) svn();
    if (m == n-1) svnl1();
    return 0;
}

using ll = long long;

void svb()
{

}
void svn()//1s 5pts
{
    long long ans = a[1];
    for (ll i = 2; i <= n; i++)
        ans &= a[i];
    cout << ans;
}
void sv1()//1s 5pts
{
    ll maxn = -11423414;
    for (ll i = 1; i <= n; i++)
        maxn = max(maxn, a[i]);
    cout << maxn <<'\n';
}
void sv2()//2s 10pts
{
    ll maxn = -123425464;
    for (ll i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            maxn = max(maxn, a[i]&a[j]);
        }
    cout << maxn;
}
void svnl1()//2s 10pts
{
    ll maxn = -142352452;
    for (ll i = 1; i <= n; i++)
    {
        ll lasx = 2147483647;
        for (ll j = 1; j <= n; j++)
        {
            if (j == i) continue;
            lasx &= a[j];
        }
        maxn = max(maxn, lasx);
    }
    cout << maxn;
}