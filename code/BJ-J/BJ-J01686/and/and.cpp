#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
long long vis[M];
long long a[M];
int n,m;
long long ans;
void dfs(int cur,long long sum)
{
    if(sum<ans) return ;
    if(cur==m+1)
    {
        ans=max(ans,sum);
        return ;
    }
    if(cur==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                dfs(cur+1,a[i]);
                vis[i]=0;
            }
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                dfs(cur+1,sum&a[i]);
                vis[i]=0;
            }
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    //for(int i=1;i<=n;i++) f[i]=(1<<30)-1;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    dfs(1,0);
    cout<<ans;
    return 0;
}
