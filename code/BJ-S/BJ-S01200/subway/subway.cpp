#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[100010],k[510],x[100010],y[100010];
long long a[5010][5010],t[5010][5010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(long long j=1;j<=n;j++)
	{
		cin>>k[j];
		for(long long i=1;i<=k[j];i++)
		{
			cin>>a[j][i]>>t[j][i];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		long long sum=0;
		sum+=w[x[i]];
		long long xx=0,yy=1;
		for(int j=1;j<=abs(y[i]-x[i])*2;j++)
		{
			if(j%2==1)
			{
				xx++;
			}
			else
			{
				yy++;
			}
			sum+=t[xx][yy];
		}
		sum+=w[y[i]];
		cout<<sum<<endl;
	}
	return 0;
}
