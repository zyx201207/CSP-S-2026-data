#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[100005],ans;
long long dis[100005],cnt[100005];
vector<int> g[100005];
void bfs(int s)
{
    queue<int> q;
    memset(dis,0x3f,sizeof dis);
    memset(cnt,0,sizeof cnt);
    q.push(s);
    dis[s]=0;
    cnt[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int v:g[u])
        {
            if (dis[u]+1<dis[v])
            {
                dis[v]=dis[u]+1;
                cnt[v]=cnt[u];
                q.push(v);
            }
            else if (dis[u]+1==dis[v])
            {
                cnt[v]+=cnt[u];
            }
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>d;
        for (int i=1;i<=n;++i)
        {
            g[i].clear();
        }
        for (int i=1;i<=n;++i)
        {
            cin>>x[i];
        }
        for (int i=1;i<=n;++i)
        {
            for (int j=i+1;j<=n;++j)
            {
                if (j==i)continue;
                if (abs(x[i]-x[j])<=d)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                    //cout<<"edge from "<<i<<" to "<<j<<endl;
                }
            }
        }
        for (int i=1;i<=n;++i)
        {
            bfs(i);
            for (int j=i+1;j<=n;++j)
            {
                ans+=(cnt[j]==2);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}