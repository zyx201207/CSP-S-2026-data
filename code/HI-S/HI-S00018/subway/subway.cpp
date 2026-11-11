#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+5,M = 1e6+5;
struct node
{
    int x;
    ll w;
    bool operator<(const node&a)const
    {
        return w>a.w;
    }
};
int w[N];
vector<int>a[505],t[505];
ll dis[M];
bool vis[M];
vector<int>road[N];
int aa[505][N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    int s = m+1;
    for(int i = 1;i<=m;++i)
    {
        cin >> w[i];
        road[i].reserve(d);
    }
    for(int i = 1;i<=n;++i)
    {
        int k;
        cin >> k;
        a[i].reserve(k);
        t[i].reserve(k);
        for(int j = 1;j<=k;++j)
        {
            int x,y;
            cin >> x >> y;
            aa[i][x] = j-1;
            road[x].push_back(i);
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }
    for(int _ = 1;_<=q;++_)
    {
        int x,y;
        cin >> x >> y;
        ll minn = 1e18;
        for(int __:road[x])
        {
            int xx = __*s+aa[__][x],man = n*s+m;
            for(int i = 0;i<=man;++i)
            {
                vis[i] = 0;
                dis[i] = 1e18;
            }
            int val = w[x]+t[__][aa[__][x]];
            dis[xx] = val;
            priority_queue<node>qq;
            qq.push({xx,val});
            while(qq.size())
            {
                int u = qq.top().x;
                qq.pop();
                if(vis[u])
                {
                    continue;
                }
                vis[u] = 1;
                int i = u/s,j = u%s;
                for(int k = j+1;k<a[i].size();++k)
                {
                    int v = i*s+k;
                    if(dis[v]>dis[u])
                    {
                        dis[v] = dis[u];
                        qq.push({v,dis[v]});
                    }
                }
                int val = t[i][j];
                for(int k:road[a[i][j]])
                {
                    int v = k*s+aa[k][a[i][j]],nval = val+t[k][aa[k][a[i][j]]];
                    ll ss = dis[u]+nval;
                    if(dis[v]>ss)
                    {
                        dis[v] = ss;
                        qq.push({v,dis[v]});
                    }
                }
            }
            for(int ___:road[y])
            {
                int yy = ___*s+aa[___][y];
                minn = min(minn,dis[yy]+t[___][aa[___][y]]+w[y]);
            }
        }
        cout << minn << '\n';
    }
    return 0;
}