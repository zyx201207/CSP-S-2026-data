#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,p;
const int N=5e5+5;
const int M=1e3+5;
int w[N];
int a[M][M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) a[i][j]=1e9;
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		int u,v;
		int t1,t2;
		cin>>x>>u>>t1>>v>>t2;
		a[u][v]=t1+t2;
		a[v][u]=t1+t2;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]>a[i][k]+a[k][j]&&i!=k&&j!=k&&i!=j) a[i][j]=a[i][k]+a[k][j];
			}
		}
	}
	while(p--)
	{
		int s,t;
		cin>>s>>t;
		cout<<a[s][t]+w[s]+w[t]<<endl;
	}
}
