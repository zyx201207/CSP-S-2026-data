#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005;
const int MAX=1e10+5;
int c,n,m,d,q,w[N],a,t,x,y,f[N][N],cnt;
void floyd()
{
	for(int k=1;k<=cnt;k++)
	{
		for(int i=1;i<=cnt;i++)
		{
			for(int j=1;j<=cnt;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=m+n;i++)
	{
		for(int j=1;j<=m+n;j++)
		{
			f[i][j]=MAX;
		}
	}
	cnt=m;
	for(int i=1;i<=n;i++)
	{
		cnt++;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			f[a][cnt]=t;
			f[cnt][a]=t;
		}
	}
	floyd();
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		if(x==y)cout<<"0\n"; 
		else cout<<f[x][y]+w[x]+w[y]<<'\n';
	}
}
