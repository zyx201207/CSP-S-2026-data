#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int x[maxn];
vector<int> g[maxn];
int n,d;
int dis[maxn];
int cnt[maxn];
queue<int> q;
void bfs(int s,int e)
{
    memset(dis,0x3f,sizeof(dis));
    q.push(s);
    dis[s]=0;
    while(q.size())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            if(dis[u]+1<dis[g[u][i]])
            {
                dis[g[u][i]]=dis[u]+1;
                cnt[g[u][i]]=1;
            }
            else if(dis[u]+1==dis[g[u][i]])
            {
                cnt[g[u][i]]++;
            }
            q.push(g[u][i]);
        }
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1; i<=n; i++)
        {
            cin>>x[i];
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(x[j]-x[i]<=d)
                {
                    g[i].push_back(j);
                }
            }
        }
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            bfs(i,n);
            for(int j=i+1; j<=n; j++)
            {
                if(cnt[j]==2)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
