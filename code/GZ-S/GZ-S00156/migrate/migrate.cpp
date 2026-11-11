//GZ-S00156 遵义市第一初级中学 张桢宇
#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n;
	long long d,l,k;
	cin>>c>>t;
	int b[t];
	for(int h=0;h<t;h++)
	{
		k=0;
		cin>>n>>d;
		long long a[n],dp[n][n];
		cin>>a[0];
		dp[0][0]=0;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<n;j++)
				dp[i][j]=dp[0][i]=INT_MAX;
			cin>>a[i];
			dp[i][i]=0;
			if(a[i]-a[i-1]<=d) dp[i-1][i]=1;
			else
			for(int q=0;q<=i;q++)
				for(int w=i-1;w<n;w++)
					dp[q][w]=-1;
		}
		for(int r=2;r<=n;r++)
			for(int i=0;i+r-1<n&&dp[i][i+r-1]>0;i++)
			{
				if(a[i+r-1]-a[i]<=d) dp[i][i+r-1]=1;
				else
				for(int j=i+1;j<i+r-1;j++)
					dp[i][i+r-1]=min(dp[i][i+r-1],dp[i][j]+dp[j+1][i+r-1]);
			}
		for(int i=0;i<n-4;i++)
			for(int j=i+3;j<n&&dp[i][j]>0;j++)
			{
				l=0;
				for(int r=i+1;r<j&&l<2;r++)
					if(dp[i][r]+dp[r+1][j]==dp[i][j]) l++;
				if(l==2) k++;
			}
		b[h]=k;
	}
	for(int i=0;i<t;i++)
		cout<<b[i]<<endl;
	return 0;
}
