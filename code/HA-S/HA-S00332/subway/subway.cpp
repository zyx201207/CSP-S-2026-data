#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
long long c,n,m,d,q,w[N],t[N][N],a[N][N],f[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int h=j+1;h<=k;h++)
			{
				f[a[i][j]][a[i][h]]=min(f[a[i][j]][a[i][h]],t[i][j]+t[i][h]);
				f[a[i][h]][a[i][j]]=min(f[a[i][h]][a[i][j]],t[i][j]+t[i][h]);
			}
		}
	}
	for(int i=1;i<=m;i++)f[i][i]=0;
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(x==y)cout<<"0\n";
		else cout<<w[x]+f[x][y]+w[y]<<"\n";
	}
	return 0;
}
