#include<bits/stdc++.h>
using namespace std;
long long w[200000],a[200000][400000],t[200000][400000],x[100005],y[100005],k[5000000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=3;i<=n+2;i++)
	{
		cin>>k[i];
		{
			for(int j=1;j<=1+2*k[i];j++)
			{
				cin>>a[i][j]>>t[i][j];
			}
		}
	}
	for(int r=1;r<=q;r++)
	{
		int x,y;
		cin>>x>>y;
		int sum=0;
		sum+=w[x];
		sum+=t[x][x];
		sum+=w[y];
		sum+=t[y][y];
		for(int i=x;i<=y;i++)
		{
			for(int j=i;j<=y;j++)
			{
				sum+=t[i][j];
			}
		}
		cout<<sum;
	}
	return 0;
}
