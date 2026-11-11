#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,d;
int a[2000005];
int ans;
int cnt,minn=1e7+5;
bool vis[2000005];
void dfs(int u,int ed,int dis)
{
    if(u==ed)
    {
        if(dis<minn)
        {
            minn=dis;
            cnt=1;
        }
        else if(dis==minn)
        {
            cnt++;
        }
        return;
    }
    vis[u]=1;
    for(int i=u+1;i<=n;i++)
    {
        if(a[i]-a[u]>d)break;
        if(!vis[i])
        {
            dfs(i,ed,dis+1);
        }
    }
    vis[u]=0;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(n<=3)
        {
            cout<<0;
            continue;
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+3;j<=n;j++)
            {
                minn=1e8+5;
                cnt=0;
                if(a[j]-a[i]<=d)continue;
                dfs(i,j,1);
                if(cnt==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
