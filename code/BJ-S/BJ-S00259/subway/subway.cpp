#include <iostream>
#include <vector>
using namespace std;
int c;
int n;
int m;
int d;
int q;
int w[500001];
bool used[500001];
int dist[500001];
vector<vector<int>> t,tt;
vector<vector<int>> g;
void dfs(int hc)
{
    for(int i=0;i<=t[hc].size();i++)
    {
        for(int j=0;j<=g[t[hc][i]].size();j++)
        {
            if(g[t[hc][i]][j]!=hc)
            {
                int p=0;
                for(int z=0;z<=t[g[t[hc][i]][j]].size();z++)
                {
                    if(t[g[t[hc][i]][j]][z]==t[hc][i])
                    {
                        p=z;
                        break;
                    }
                }
                dist[g[t[hc][i]][j]]=min(dist[g[t[hc][i]][j]],dist[hc]+tt[hc][i]+tt[g[t[hc][i]][j]][p]);
                dfs(g[t[hc][i]][j]);
            }
        }
    }
}
int main()
{
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
    cin>>c;
    cin>>n;
    cin>>m;
    cin>>d;
    cin>>q;
    g.resize(m);
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    t.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        int a,tt1;
        cin>>a>>tt1;
        t[i].push_back(a);
        tt[i].push_back(tt1);
        g[a].push_back(i);
    }
    for(int i=1;i<=q;i++)
    {
        int r,r_;
        cin>>r>>r_;
        for(int i=1;i<=n;i++)
        {
            if(r!=i)
            dist[i]=1e9;
        }
        for(int q=0;q<=g[r].size();q++)
        {
            dist[g[r][q]]=0;
            dfs(g[r][q]);
        }
        int ans=1e9;
        for(int i=1;i<=n;i++)
        {
            bool f=0;
            for(int z=0;z<=t[i].size();z++)
            {
                if(t[i][z]==r_)
                {
                    f=1;
                    break;
                }
            }
            if(f&&dist[i]<ans)
            {
                ans=dist[i];
            }
        }
        cout<<ans<<endl;
    }
}
