#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],f[1005][1005];
struct bsc
{
	int a,t;
}s[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d",&s[i].a,&s[i].t);
			for(int j=i-1;j;j--)
			{
				f[s[i].a][s[j].a]=s[i].t+s[j].t;
				f[s[j].a][s[i].a]=s[i].t+s[j].t;
			}		
		}	
	}	
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==j||j==k||i==k) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",w[x]+w[y]+f[x][y]);
	}
	return 0;
}