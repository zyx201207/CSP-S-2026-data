#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005];
ll l,r,ans;
void dfs(ll where,ll choose,ll num,ll x)
{
    if(num<0)return;
    if(where==n)
    {
        ans=max(choose,ans);
        return ;
    }
    dfs(where+1,choose+1,num-abs(a[where]-x),x);
    dfs(where+1,choose,num,x);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    bool Axz=0,Bxz=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)Axz=1;
        if(i>1&&!(a[i]-a[i-1]==a[i-1]-a[i-2]))Bxz=1;
    }
    if(!Axz)
    {
        cout<<m<<endl;
        return 0;
    }
    if(!Bxz)
    {
        if(m%2==1)cout<<m/2+1;
        else cout<<m/2;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        dfs(0,0,m,a[i]);
    }
    cout<<ans;
    return 0;
}
