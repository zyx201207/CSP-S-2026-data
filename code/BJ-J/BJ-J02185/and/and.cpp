#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[100005],Max;
void dfs(ll k,ll cnt,ll now)
{
    if(k==m)
    {
        Max=max(Max,cnt);
        return;
    }
    for(ll i=now+1;i<=n;i++)
    {
        //cout<<a[now]<<" "<<a[i]<<"\n";
        dfs(k+1,(cnt&a[i]),i);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) dfs(1,a[i],i);
    cout<<Max;
    return 0;
}
