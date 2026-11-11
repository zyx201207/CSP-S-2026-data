#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,k=-1,ans=-1;
void dfs(int i,int sum,int h)
{
    if(h==m)
    {
        ans=max(sum,ans);
        return;
    }
    for(int u=i+1;u<=n;u++)
    {
        dfs(u,sum&a[u],h+1);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        dfs(i,a[i],1);
    }
    cout<<ans;

    return 0;
}
