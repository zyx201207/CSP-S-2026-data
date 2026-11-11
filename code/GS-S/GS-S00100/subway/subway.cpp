#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1010],x,y,k[1010],a[1010][1010],t[1010][1010],g;
void more(int e)
{
	int s;
	for(int u=1;u<=n;u++)
	{
		for(int i=2;i<=2*k[u]-1;i++)
		{
			if(t[x][e]<t[x][e-1])
			{
				s=e;
			}
		}
		for(int j=1;j<=k[u];j++)
		{
			if(a[s][j]==a[y][j])
			{
				g+=t[s][y];
			}
			else
			{
				more(1);
			}
		}
	}
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		g=0;
		g=g+w[x]+t[x][x]+w[y];
		for(int u=1;u<=n;u++)
		{
			for(int j=1;j<=k[u];j++)
			{
				if(a[x][j]==a[y][j])
				{
					g+=t[x][y];
				}
				else
				{
					more(j);
				}
			}
		}
		cout<<g<<endl;
	}
	
	return 0;
}
