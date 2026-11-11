#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
ll n,d;
ll x[2000005];
ll dis[2000005];
bool vis[2000005];
ll ans3=0;
void bfs(int a,int b)
{
    queue<int> q;
    q.push(a);
    vis[a]=1;
    while(q.size())
    {
        int cur=q.front();
        q.pop();
        for(int i=cur+1;i<=b;i++)
        {
            if(x[i]-x[cur]<=d&&!vis[i])
            {
                vis[i]=1;
                dis[i]=dis[cur]+1;
                q.push(i);
            }else break;
        }
    }
}
void dfs2(int a,int b,int key,int step)
{
    if(a==b&&step==key)
    {
        ans3++;
        return;
    }
    for(int i=a+1;i<=b;i++)
    {
        if(x[i]-x[a]<=d)
        {
            dfs2(i,b,key,step+1);
        }else break;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                bfs(i,j);
                ll ans2=dis[j];
                for(int k=i;k<=j;k++)
                {
                    dis[k]=0;
                    vis[k]=0;
                }
                dfs2(i,j,ans2,0);
                if(ans3==2)
                {
                    ans++;
                }
                ans3=0;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
