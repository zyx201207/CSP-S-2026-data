#include<bits/stdc++.h>
using namespace std;
long long n,m,q,k,f[510][510],mn,a[510000];
vector <long long> vt[510000],qz[510000];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(f,0x3f,sizeof(f));
    long long u,v,w,ls,lsu,lsv;
    cin>>u>>n>>m>>v>>q;
    for(long long i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++)
    {
        f[i][i]=0;
        v=m+i;
        cin>>k;
        for(long long j=1;j<=k;j++)
        {
            cin>>u>>w;
            vt[u].push_back(v);
            qz[u].push_back(w);
        }
    }
    for(long long i=1;i<=m;i++)
    {
        ls=vt[i].size();
        if(ls<2)
        {
            continue;
        }
        for(long long jx=0;jx<ls;jx++)
        {
            for(long long jy=0;jy<ls;jy++)
            {
                u=vt[i][jx]-m;
                v=vt[i][jy]-m;
                w=qz[i][jx]+qz[i][jy];
                if(u==v)
                {
                    continue;
                }
                f[u][v]=min(f[u][v],w);
            }
        }
    }
    for(long long t=1;t<=n;t++)
    {
        for(long long i=1;i<=n;i++)
        {
            for(long long j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][t]+f[t][j]);
            }
        }
    }
    for(long long i=1;i<=q;i++)
    {
        cin>>u>>v;
        lsu=vt[u].size();
        lsv=vt[v].size();
        mn=9e18;
        for(long long jx=0;jx<lsu;jx++)
        {
            for(long long jy=0;jy<lsv;jy++)
            {
                w=qz[u][jx]+qz[v][jy]+f[vt[u][jx]-m][vt[v][jy]-m];
                mn=min(mn,w);
            }
        }
        cout<<mn+a[u]+a[v]<<"\n";
    }
    return 0;
}
//37 min
