#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> g[N];
int dis[N];
int u[N],v[N];
queue<int> q;
int cbit(int x)
{
    int ans=0;
    while (x)
        ans++,x&=x-1;
    return ans;
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    if (13<=c&&c<=14)
    {
        while (t--)
        {
            int n,k;
            cin>>n>>k;
            for (int i=1,u,v;i<n;i++)
                cin>>u>>v;
            if (k>=n)
            {
                cout<<0<<"\n";
                continue;
            }
            cout<<max((n/2-k+3)/4,0)+1<<"\n";
        }
        return 0;
    }
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        for (int i=1;i<=n;i++)
            g[i].clear();
        for (int i=1;i<n;i++)
        {
            cin>>u[i]>>v[i];
            g[u[i]].push_back(v[i]);
            g[v[i]].push_back(u[i]);
        }
        int ans=n;
        for (int s=0;s<(1<<n);s++)
        {
            int cnt=cbit(s);
            if (cnt>k)
                continue;
            for (int i=1;i<=n;i++)
            {
                if (s>>(i-1)&1)
                    dis[i]=0;
                else dis[i]=1e9;
            }
            for (int i=1;i<n;i++)
                if (!dis[u[i]]&&!dis[v[i]])
                    cnt--;
            if (cnt>2)
                continue;
            for (int i=1;i<=n;i++)
                if (s>>(i-1)&1)
                    q.push(i);
            while (!q.empty())
            {
                int u=q.front();
                q.pop();
                for (int i=0;i<g[u].size();i++)
                    if (dis[u]+1<dis[g[u][i]])
                        dis[g[u][i]]=dis[u]+1,q.push(g[u][i]);
            }
            int as=0;
            for (int i=1;i<=n;i++)
                as=max(as,dis[i]);
            ans=min(ans,as);
        }
        cout<<ans<<"\n";
    }
    return 0;
}