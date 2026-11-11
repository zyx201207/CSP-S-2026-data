#include<bits/stdc++.h>
using namespace std;
long long n[500005],m[500005],dp[5005][5005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>n[i];
	}
	if(a<5001)	
	{	sort(n+1,n+a+1);
		int sj=1;
		for(int i=1;i<=a;i++)
		{
			int zd=n[i];
			for(int j=i+1;j<=a;j++)
			{
				if(n[j]>zd)
				{
					dp[i][j]=dp[i][j-1]+(n[j]-zd)*(j-i);
					zd=n[j];
				}
				else
					dp[i][j]=dp[i][j-1]+(zd-n[j]);
				if(dp[i][j]<=b)
					sj=max(sj,j-i+1);
			}
		}
		cout<<sj;
	}
	else
	{
		sort(n+1,n+a+1,cmp);
		int sum=1;
		for(int i=2;i<=a;i++)
		{
			if(b>=(n[1]-n[i]))
			{
				sum++;
				b-=(n[1]-n[i]);
			}
		}
		cout<<sum;
	}
	return 0;
} 
