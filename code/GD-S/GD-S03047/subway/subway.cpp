#include<bits/stdc++.h>
using namespace std;
struct road
{
	int fin,tim;
};
int jilu[501][20001];
int c,n,m,d,q;
int w[500005];
int ans[505][505];
vector<road> a[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ans,0x3f,sizeof(ans));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1; i<=n; i++)
	{
		int k1;
		scanf("%d",&k1);
		for(int j=1; j<=k1; j++)
		{
			int ddd1,ddd2;
			scanf("%d%d",&ddd1,&ddd2);
			jilu[i][ddd1]=ddd2;
		}
	}
	for(int i=1; i<n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			for(int b1=1; b1<=m; b1++)
			{
				if(jilu[i][b1]!=0 && jilu[j][b1]!=0)
				{
					road temp;
					temp.tim=jilu[i][b1]+jilu[j][b1];
					for(int b2=1; b2<=m; b2++)
					{
						if(jilu[i][b2]==0) continue;
						for(int b3=1; b3<=m; b3++)
						{
							if(jilu[j][b3]!=0)
							{
								temp.fin=b3;
								a[b2].push_back(temp);
								temp.fin=b2;
								a[b3].push_back(temp);
								
							}
						}
					}
				}
			}
		}
	}
	
	for(int i=1; i<=m; i++)
	{
		for(int j=0; j<a[i].size(); j++)
		{
			if(a[i][j]!=0)
			{
				ans[i][j]=a[i][j].tim;
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(jilu[i][j]==0)
			{
				continue;
			}
			if(i==j)
			{
				ans[i][j]=0;
				ans[j][i]=0;
				continue;
			}
			ans[j][i]=0;
			ans[i][j]=ans[j][i];
		}
	}
	
//	for(int i=1; i<=m; i++)
//	{
//		for(int j=1; j<=m; j++)
//		{
//			cout<<ans[i][j]<<' ';
//		}cout<<endl;
//	}
	for(int k=1; k<=m; k++)
	{
		for(int i=1; i<=m; i++)
		{
			int xd=a[k].size();
			for(int j=1; j<=xd; j++)
			{
				if(ans[i][k]+a[k][j].tim<ans[i][j])
				{
					ans[i][j]=ans[i][k]+a[k][j].tim;
				}
			}
		}
	}
	
	while(q--)
	{
		int st,en;
		scanf("%d%d",&st,&en);
		printf("%d\n",ans[st][en]+w[st]+w[en]);
	}
	return 0;
}
