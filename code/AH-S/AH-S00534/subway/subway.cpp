#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,sl=0;
int vis[10005][10005]={0};
void dij()
{
	for(int l=1;l<=2;l++)
	{
		for(int i=1;i<=2*m+n;i++)
			for(int j=1;j<=2*m+n;j++)
				for(int k=1;k<=2*m+n;k++)
					if((long long)(vis[i][k])>=(long long)((long long)(vis[i][j])+(long long)(vis[j][k]))&&i!=j&&i!=k&&j!=k)
						{
							vis[i][k]=vis[i][j]+vis[j][k];
						}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=3*m;i++)
		for(int j=1;j<=3*m;j++)
			if(i!=j) vis[i][j]=INT_MAX;
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		vis[i+m][i]=x;
		vis[i][i+m]=x;
	}
	int lx=0;
	for(int i=1;i<=n;i++)
	{
		int tc;
		cin>>tc;
		for(int j=1;j<=2*tc;j++)
		{
			int x;
			cin>>x;
			if(j%2==0)
			{
				sl++;
				vis[m+m+i][lx]=x;
				vis[lx][m+m+i]=x;
			}
			lx=x;
		}
	}
	dij();
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<vis[x+m][y+m]<<'\n';
	}
	return 0;
}
