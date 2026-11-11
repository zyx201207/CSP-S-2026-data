#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,a,x,y,l[500010][30];
long long sd[510][510],w[500010],t[500010][30],T,_min;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&w[i]);
        t[i][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            scanf("%d%lld",&a,&T);
            t[a][0]++;
            t[a][t[a][0]]=T;
            l[a][t[a][0]]=i;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            sd[i][j]=sd[j][i]=9e18;
            if(i==j)
                sd[i][j]=sd[j][i]=0;
        }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<t[i][0];j++)
            for(int k=j+1;k<=t[i][0];k++)
                if(t[i][j]+t[i][k]<sd[l[i][j]][l[i][k]])
                    sd[l[i][j]][l[i][k]]=sd[l[i][k]][l[i][j]]=t[i][j]+t[i][k];
    }
    for(int i=1;i<=9;i++)
        for(int j=1;j<n;j++)
            for(int k=j+1;k<=n;k++)
                for(int o=1;o<=n;o++)
                    if(sd[j][o]<sd[j][k]-sd[k][o])
                        sd[j][k]=sd[k][j]=sd[j][o]+sd[k][o];

    for(int i=1;i<=q;i++)
    {
        _min=9e18;
        scanf("%d%d",&x,&y);
        for(int j=1;j<=t[x][0];j++)
            for(int k=1;k<=t[y][0];k++)
                if(t[x][j]+t[y][k]<_min-sd[l[x][j]][l[y][k]])
                    _min=sd[l[x][j]][l[y][k]]+t[x][j]+t[y][k];
        printf("%lld\n",w[x]+w[y]+_min);
    }
    return 0;
}
