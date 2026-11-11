#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],tmp,opx,opy;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    int val[m+5][m+5];
    memset(val,0x7f,sizeof val);
    for(int i=1;i<=m;i++){scanf("%d",&w[i]);val[i][i]=0;}
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tmp);
        int vis[tmp+5][3];
        for(int j=1;j<=tmp;j++) scanf("%d%d",&vis[j][1],&vis[j][2]);
        for(int j=1;j<=tmp;j++)
        {
            for(int k=1;k<=tmp;k++)
            {
                if(j==k) continue;
                val[vis[j][1]][vis[k][1]]=vis[j][2]+vis[k][2];
                val[vis[k][1]][vis[j][1]]=vis[j][2]+vis[k][2];
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=m;k++)
			{
				if(val[i][k]==0x7f7f7f7f||val[k][j]==0x7f7f7f7f) continue;
            	val[i][j]=min(val[i][j],val[i][k]+val[k][j]);
			}
        }
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&opx,&opy);
        printf("%d",val[opx][opy]+w[opx]+w[opy]);
        if(i!=q) printf("\n");
    }
    return 0;
}
