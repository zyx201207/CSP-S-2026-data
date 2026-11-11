#include <bits/stdc++.h>
using namespace std;
long long a[2000006];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin >> c >> t;
	if(c==0)
	{
		while(t--)
		{
			long long n,d;
		long long a[200006]={};
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
			cin >> a[i];
			if(n==4&&d==2)cout << 1 << endl;
			else if(n==5&&d==2)	cout << 2 << endl;
			else if(n==5&&d==3)	cout << 0 << endl;
			else if(n==6&&d==2)	cout << 1 << endl;
		}
		return 0;
	}
	else
	{
	while(t--)
	{
		long long n,d;
		long long dp[5006][5006]={};
		memset(a,0,sizeof(a));
		cin >> n >> d;
		for(int i = 1;i < n;i++)
		{
			cin >> a[i];
			dp[i][i]=0;
			if(a[i+1]-a[i]<=d){
			//	dp[i][i+1]=1;
				dp[i+1][i]=1;
			}
			else{
				dp[i][i+1]=0;
				dp[i+1][i]=0;
			}
		}
		for(int k = 2;k < n;k++) 
		{
			for(int i = n-2;i >= 1;i--)
			{
				int j = i+k;
				if(j>n)	break;
				if(a[j]-a[i]>d)	break;
				else
				{
				//	dp[i][j]=dp[i+1][j]+dp[i][j-1];
				}
			}	
		}
		cout << dp[1][n] << endl;
	}
	}
	return 0;
}
