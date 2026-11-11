#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
using namespace std;
int c,t,n;
const int N=2e6+10;
ll d,a[N];
int ct1[N],ct2[N],ct3[N];
//3：不能即刻混淆。。。。
ll solve(int l,int r)
{
    for(int i=l;i<=r;i++) ct1[i]=ct2[i]=ct3[i]=0;
    ll ans=0;
    int ps=l,ls=l,pps=-1;
    for(int i=l;i<=r;i++)
    {
        while(ps<r&&a[ps+1]-a[i]<=d) ps++;
        ans+=1ll*ct2[i]*(ps-ls);
        ans+=1ll*(ls-max(pps,i))*ct1[i];
        ct1[i]+=ct3[i];
        if(ls!=ps) 
        {
            if(ls==ps-1) ct3[ps]+=ct1[i],ct1[ps]++;
            else ct1[ps]+=ct1[i]+1;
            ct2[ps]+=ct2[i];
        }
        else 
        {
            if(pps!=ls) ct2[ps]+=ct1[i]-ct3[i];
            ct1[ps]++;
        }
        // clog<<i<<" "<<ct1[i]<<' '<<ct2[i]<<' '<<ps<<' '<<ans<<endl;
        pps=ls,ls=ps;
    }
    return ans;
}
ll solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1;
    ll ans=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]>d) ans+=solve(l,i-1),l=i;
    }
    ans+=solve(l,n);
    return ans;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--) cout<<solve()<<"\n";
    return 0;
}