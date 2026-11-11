#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500001],k[501],cn,x,y,nn,en[500001],hn[500001],dis[1500001],hmm;
vector <int> a[501],t[501];
vector <pair <int,int> > e[1500001];
priority_queue <pair <int,int>,vector <pair <int,int> >,greater <pair <int,int> > > que;
struct Ni
{
    int type,ss,rn;
}ni[1500001];
void dijk (int x)
{
    memset(dis,0x3f,sizeof(dis));
    dis[x]=0;
    que.push({0,x});
    while (!que.empty())
    {
        int u=(que.top()).second,dist=(que.top()).first;
        que.pop();
        //cout << u << " " << dist << endl;
        for (auto i:e[u])
        {
            int v=i.first,w=i.second;
            //cout << v << " " << w << " " << dis[v] << endl;
            if (dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                que.push({dis[v],v});
            }
        }
    }
}
signed main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++)
    {
        cin >> w[i];
        ni[++nn]={0,i,0};
        en[i]=nn;
        ni[++nn]={1,i,0};
        hn[i]=nn;
        e[nn-1].push_back({nn,w[i]});
        e[nn].push_back({nn-1,w[i]});
    }
    for (int i=1;i<=n;i++)
    {
        cin >> k[i];
        for (int j=1;j<=k[i];j++)
        {
            cin >> cn;
            a[i].push_back(cn);
            ni[++nn]={2,a[i][j-1],i};
            if (j>1)
            {
                e[nn-1].push_back({nn,0});
                e[nn].push_back({nn-1,0});
            }
            cin >> cn;
            //t[i].push_back(cn);
            e[nn].push_back({hn[a[i][j-1]],cn});
            e[hn[a[i][j-1]]].push_back({nn,cn});
        }
    }
    for (int i=1;i<=q;i++)
    {
        cin >> x >> y;
        dijk(en[x]);
        cout << dis[en[y]] << "\n";
    }
    return 0;
}
