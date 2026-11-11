#include <bits/stdc++.h>
#define M 500005
#define N 10005
#define T 505
#define inf 0x3f3f3f3f
#define int long long
using namespace std;
int n,m,c,d,q,w[M],e[N][N],k[T],p[T][25],l[T][25];
vector<int>gr[T];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(e,inf,sizeof e);
    for(int i=1;i<=m;i++)cin>>w[i];
    bool fl=true,f2=true;int same;
    for(int i=1;i<=n;i++)
    {
        int idx=m+i;cin>>k[i];
        if(k[i]>2)fl=false;
        for(int j=1;j<=k[i];j++)
        {
            cin>>p[i][j]>>l[i][j];if(i==1&&j==1)same=l[i][j];
            if(l[i][j]!=same)f2=false;
            e[p[i][j]][idx]=e[idx][p[i][j]]=l[i][j];
        }
    }int t=n+m;
    for(int i=1;i<=t;i++)e[i][i]=0;
    if(f2)
    {
        t=n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k[i];j++)
            {
                if(!gr[p[i][j]].empty())
                {
                    for(int u:gr[p[i][j]])
                        e[u][i]=e[i][u]=1;
                }
                gr[p[i][j]].push_back(i);
            }
        }
        for(int k=1;k<=t;k++)
            for(int i=1;i<=t;i++)
                for(int j=1;j<=t;j++)
                    if(e[i][k]+e[k][j]<e[i][j])
                        e[i][j]=e[i][k]+e[k][j];
        while(q--)
        {
            int x,y;cin>>x>>y;
            int res=inf;
            for(int i:gr[x])
                for(int j:gr[y])
                    res=min(res,e[i][j]);
            cout<<(res+2ll+(res!=0))*same+w[x]+w[y]<<"\n";
        }
    }
    else
    {
        if(fl==true)
        {
            t=m;
            for(int i=1;i<=n;i++)
            {
                int s=p[i][1],t=p[i][2];
                e[s][t]=e[t][s]=l[i][1]+l[i][2];
            }
        }
        for(int k=1;k<=t;k++)
            for(int i=1;i<=t;i++)
                for(int j=1;j<=t;j++)
                    if(e[i][k]+e[k][j]<e[i][j])
                        e[i][j]=e[i][k]+e[k][j];
        while(q--)
        {
            int x,y;cin>>x>>y;
            cout<<e[x][y]+w[x]+w[y]<<"\n";
        }
    }
    return 0;
}
