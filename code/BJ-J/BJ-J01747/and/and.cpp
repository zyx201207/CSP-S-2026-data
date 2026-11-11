#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
ll n,m;
ll a[200005];
bool v[200005];
vector<ll> vt;
bool check(ll x)
{
    ll log=log2(x);
    ll t=pow(2,log);
    return (t==x);
}
ll maxx=-1;
void dfs(ll now)
{
    vt.push_back(a[now]);
    if(vt.size()==m)
    {
        ll _and;
        for(ll ii=0; ii<vt.size(); ii++)
        {
            if(!ii)
            {
                _and=vt[ii];
            }
            else
            {
                _and&=vt[ii];
            }
        }
        maxx=max(maxx,_and);
    }
    else
    {
        for(ll iii=now+1; iii<=n; iii++)
        {
            dfs(iii);
        }
    }
    vt.pop_back();
    return;
}
ll i;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool vv=1;
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
        if(!check(a[i]+1))
        {
            vv=0;
        }
    }
    if(vv)
    {
        sort(a+1,a+1+n,greater<ll>());
        cout<<a[m];
    }
    else
    {
        for(i=1; i<=n-m+1; i++)
        {
            dfs(i);
        }
        cout<<maxx;
    }
    return 0;
}
/*
  RP++
  AC++
  AK++
*/
