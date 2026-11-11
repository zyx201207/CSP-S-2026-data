#include<bits/stdc++.h> 
using namespace std;
struct{
	int r=0,o,e;
}g[500005];
int b;
int c,n,m,d,q;
int w[500005],k[505],a[505][505],t[25][505],x[10005],y[10005];
void fin(int b) 
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			if(g[a[i][j]].r==0)
			{
				g[a[i][j]].r+=w[a[i][j]];
				g[a[i][j]].o=a[i][j];
				fin(y[i]);
			}
			if(g[a[i][j]].o==b)
			{
				g[a[i][j]].r+=w[a[i][j]];
				
			}
			
		}
	}
}
int main()
{
	cin>>c>>n>>m>>d>>q;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];i++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		fin(y[i]);
	}
	return 0; 
}
