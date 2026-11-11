#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
ifstream fin("subway.in");
ofstream fout("subway.out");
#define cin fin
#define cout fout
long long c,n,m,d,q;
int w[500001],k[501],mp[501][500001],t[501][500001];
long long dis[501][501],g[501][501];
set<int>zd[500001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(g,0x3f,sizeof(g));
    for(long long i=1;i<=m;i++)
        cin>>w[i];
    for(long long i=1;i<=n;i++)
    {
        g[i][i]=0;
        cin>>k[i];
        for(long long j=1;j<=k[i];j++)
        {
            long long now;
            cin>>now>>t[i][j];
            mp[i][now]=j;
            if(!zd[now].empty())
            {
                for(auto v:zd[now]) //v是车站
                {
                    long long vj=mp[v][now];
                    g[i][v]=min(g[i][v],1ll*t[i][j]+t[v][vj]);
                    g[v][i]=min(g[v][i],1ll*t[i][j]+t[v][vj]);
                }
            }
            zd[now].insert(i);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=g[i][j];
    //cerr<<"pre prepration"<<endl;
    for(long long tmp=1;tmp<=n;tmp++)
        for(long long i=1;i<=n;i++)
            for(long long j=1;j<=n;j++)
                if(dis[i][j]>dis[i][tmp]+dis[tmp][j])
                    dis[i][j]=dis[i][tmp]+dis[tmp][j];
    //cerr<<"shortest path"<<endl;
    // for(int i=1;i<=m;i++)
    //     cerr<<zd[i].size()<<endl;
    while(q--)
    {
        long long x,y;
        cin>>x>>y;
        long long cur=w[x]+w[y],ans=LONG_LONG_MAX;
        //cerr<<zd[x].size()<<' '<<zd[y].size()<<endl;
        for(auto it1:zd[x])
            for(auto it2:zd[y])
            {
                int ztx=mp[it1][x],zty=mp[it2][y];
                ans=min(ans,cur+1ll*t[it1][ztx]+1ll*t[it2][zty]+dis[it1][it2]);
            }
        cout<<ans<<endl;
    }
}
