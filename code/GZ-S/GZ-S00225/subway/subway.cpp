//GZ-S00225  遵义市第十九中学  吴韩飞
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m],ki;
	cin>>ki;
	int a[n+2][ki+2],t[n+2][ki+2];
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=ki;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	int s[q+2][q+2],f[q+2][q+2];
	for(int i=1;i<=q;i++)
	{
		cin>>s[i][i]>>f[i][i];
	}
	int sum[q+2];
	for(int i=1;i<=n;i++)
	{
		for(int j=s[i][i];j<=f[i][i];j++)
		{
			sum[i]+=w[j]+t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<sum[i];
	}
	return 0;
}
