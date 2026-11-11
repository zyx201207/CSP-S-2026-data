#include<bits/stdc++.h>
using namespace std;
int id,t;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> id >> t;
    while(t--)
    {
        int n,d,a[5005],ans=0;
        vector <int> e[5005];
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = i+1;j <= n;j++)
            {
                if(abs(a[i]-a[j])<=d)
                {
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
        }
        for(int i = 1;i <= n;i++)
        {
            queue <int> q;
            int vis[600005];
            int dis[600005];
            q.push(i);
            dis[i]=0;
            vis[i]=1;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                for(int v:e[u])
                {
                    if(dis[v]==dis[u]+1)
                    {
                        vis[v]+=vis[u];
                        if(vis[v]==2)ans++;
                        else ans--;
                    }
                    else if(dis[v]>dis[u]+1 or vis[v]==0)
                    {
                        vis[v]=1;
                        dis[v]=dis[u]+1;
                        q.push(v);
                    }
                }
            }
        }
        cout << ans/2 <<"\n";
    }
    return 0;
}