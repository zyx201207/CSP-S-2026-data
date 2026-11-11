#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510;
const int M=2e4+10;
int w[M];
int k[N];
int a[N][M];
int t[N][M];
ll f[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f3f3f3f,sizeof(f));
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		f[i][i]=0;
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		for (int j=1;j<=k[i];j++)
		{
			for (int o=j+1;o<=k[i];o++)
			{
				f[a[i][j]][a[i][o]]=min(f[a[i][j]][a[i][o]],(long long)w[a[i][j]]+t[i][j]+t[i][o]+w[a[i][o]]);
				f[a[i][o]][a[i][j]]=min(f[a[i][o]][a[i][j]],f[a[i][j]][a[i][o]]);
			}
		}
	}
	for (int o=1;o<=m;o++)
	{
		for (int i=1;i<=m;i++)
		{
			for (int j=1;j<=m;j++)
			{
				if (i!=j && j!=o && i!=o)
				{	
					f[i][j]=min(f[i][j],f[i][o]+f[o][j]-2*w[o]);
				}
			}
		}
	}
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]<<endl;
	}
	return 0;	
} 
