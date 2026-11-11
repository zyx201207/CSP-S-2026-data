#include<bits/stdc++.h>
using namespace std;
int ans[1505][1505];
int p[500005];
int c,n,m,d,q;
int cnt;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	memset(ans,0x3f,sizeof(ans));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		int x; cin>>x;
		ans[i][i+m]=ans[i+m][i]=x;
	}
	cnt=m*2;
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,w;
			cin>>x>>w; cnt++;
			ans[x+m][cnt]=ans[cnt][x+m]=w;
			p[j]=cnt;
		}
		cnt++;
		for(int j=1;j<=k;j++)
		{
			ans[p[j]][cnt]=ans[cnt][p[j]]=0;
		}
	}
	for(int k=1;k<=cnt;k++)
	{
		for(int i=1;i<=cnt;i++)
		{
			for(int j=1;j<=cnt;j++)
			{
				ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<ans[x][y]<<"\n";
	}
	return 0;
} 
