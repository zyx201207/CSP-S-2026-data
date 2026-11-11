#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[100100],dp[10010][10010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		dp[1][i]=a[i];
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int b=0;
			for(int w=1;w<=n;w++)
			{
				if(w==j) continue;
				b=max(b,(dp[i-1][j]&a[w]));
			}
			dp[i][j]=max(dp[i][j],b);
		}
	}
	int c=0;
	for(int i=1;i<=n;i++) c=max(c,dp[m][i]);
	cout<<c;
	return 0; 
 } 
