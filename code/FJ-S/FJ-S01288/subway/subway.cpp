#include <bits/stdc++.h>
using namespace std;
int w[500005];
int a[503][5005];
int t[503][5005];
int k[5005];
long long f[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		f[0][i]=w[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			f[i][j]=w[i]+w[j]+t[i][j]+t[i][i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int o=1;o<=m;o++)
			{
				f[i][j]=min(f[i][j],f[i][o]+f[o][j]-w[o]-w[o]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		cout<<f[x][y]<<'\n';
	}
	return 0;
}
