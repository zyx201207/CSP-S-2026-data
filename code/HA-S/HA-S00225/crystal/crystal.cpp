#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+5;
long long a[N];
long long n,m;

bool Cmp(const long long &a,const long long &b)
{
	return a<b;
}
long long dp[5][N]; 
long long cnt[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	
	}
	sort(a+1,a+n+1,Cmp);
	
	for(int i=2;i<=n;i++)
	{
		cnt[i]=a[i]-a[i-1];
	}
	int arr=1;
	dp[1][0]=0;
	cnt[1]=0;
	int Max=0;
	bool dpb=0;
	cnt[0]=0;
	for(int i=1;i<=n&&dpb==0;i++)
	{
		
		dp[1][i]=dp[1][i-1]+cnt[i]*(i-1);
		dp[2][i]=dp[1][i];
	 
		if(dp[1][i]>m&&dpb==0)
		{
			for(int j=i;j<=n;j++)
			{
				dp[2][j]=dp[2][j-1]+cnt[j]*(j-2)-a[arr++];
				if(dp[2][j-1]<=m&&dp[2][j]>m)
				{
					Max=max(Max,j-1);
				}
		 
			}
			Max=max(Max,i-1);
			dpb=1;
		}
	
		
	}
	cout<<Max;
	return 0;
}
