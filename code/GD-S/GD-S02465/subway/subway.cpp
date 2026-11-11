#include<bits/stdc++.h>
using namespace std;
const long long N=7e5+7,M=607,INF=1145141919810;
long long n,m,i,j,k,C,d,q,p[20*N][3],t[N],g[M][M],W[N],a[N],v,cut,u;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(i=0;i<N;i++) t[i]=-1;
    cin>>C>>n>>m>>d>>q;
    for(i=0;i<m;i++) cin>>W[i];
    for(i=0;i<M;i++) for(j=0;j<M;j++) g[i][j]=INF;
    for(i=0;i<n;i++)
    {
        cin>>k;
        for(j=0;j<k;j++)
        {
            cin>>u>>v;
            u--;
            p[cut][0]=i;
            p[cut][1]=t[u];
            p[cut][2]=v;
            t[u]=cut++;
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=t[i];j!=-1;j=p[j][1])
        {
            for(k=t[i];k!=j;k=p[k][1])
            {
                g[p[j][0]][p[k][0]]=min(g[p[j][0]][p[k][0]],p[j][2]+p[k][2]);
            }
        }
    }
    for(i=0;i<n;i++) g[i][i]=0;
    for(i=0;i<n;i++) for(j=0;j<n;j++) g[i][j]=g[j][i]=min(g[i][j],g[j][i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                g[j][k]=min(g[j][k],g[j][i]+g[i][k]);
            }
        }
    }
    for(;q>0;q--)
    {
        long long x,y,ans=INF;
        cin>>x>>y;x--;y--;
        for(i=t[x];i!=-1;i=p[i][1])
        {
            for(j=t[y];j!=-1;j=p[j][1])
            {
                ans=min(ans,g[p[i][0]][p[j][0]]+p[i][2]+p[j][2]);
            }
        }
        cout<<ans+W[x]+W[y]<<"\n";
    }
    return 0;
}
//这集神了，连续两年T2都是图论
