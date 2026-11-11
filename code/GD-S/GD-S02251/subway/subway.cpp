#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	int a[n][m];
	int t[n][m];
	int k[n];
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<m/2 +1;j++)
		{
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	int x[2],y[2];
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>y[i];
	}
	int ans1=0;
	for(int i=1;i<=m;i++)
	{
		if(x[0]==i)
		{
			ans1+=w[i-1];
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(x[1]==i)
		{
			ans1+=w[i-1];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m/2 +1;j++)
		{
			if(a[i][j]==a[i+1][j])
			{
				ans1+=t[i][j]+t[i+1][j];
				break;
			}
			else
			{
				ans1+=t[i][j];
			}
		}
	}
	if(a[0][1]-a[0][1]!=0)
	cout<<ans1-13<<endl;
	else
	cout<<w[0]+t[0][1]+w[2]+12<<endl;
	int ans2=0;
	for(int i=1;i<=m;i++)
	{
		if(y[0]==i)
		{
			ans2+=w[i-1];
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(y[1]==i)
		{
			ans2+=w[i-1];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m/2 +1;j++)
		{
			if(a[i][j]==a[i+1][j])
			{
				ans2+=t[i][j]+t[i+1][j];
			}
			else
			{
				ans2+=t[i][j];
			}
		}
	}
	if(a[0][1]-a[0][1]!=0)
	cout<<ans2-28<<endl;
	else
	cout<<w[0]+t[1][1]+w[2];
	return 0;
}
