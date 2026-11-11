#include<bits/stdc++.h>
using namespace std;
const int N=3e4+10;
int n,m;
int a[N];
int dp[N][N];
bool v[N][N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[1][i]=a[i];
		v[i][i]=1;
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x=dp[i][j];
			int id=0;
			for(int z=1;z<=n;z++)
			if(v[j][z]==0)
			{
				if(dp[i-1][j]&a[z]>x)x=dp[i-1][j]&a[z],id=z;
			}
			dp[i][j]=x,v[j][id]=1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(dp[m][i],ans);
	cout<<ans;
	return 0;
}

