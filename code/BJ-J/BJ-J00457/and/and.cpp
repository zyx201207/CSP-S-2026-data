#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN=2e5+10;
int a[MAXN];
bool vis[MAXN];
int ans;
void dfs(int dep,int anss)
{
    if(dep==m)
    {
        ans=max(ans,anss);
        return;
    }//ans return
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(dep+1,anss&a[i]);
            vis[i]=0;
        }
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        vis[i]=1;
        dfs(1,a[i]);
        vis[i]=0;
    }
    cout<<ans;
    return 0;
}
