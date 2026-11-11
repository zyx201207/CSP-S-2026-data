#include<bits/stdc++.h>
using namespace std;

int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1];
	string s[n+1];	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=n;i++)
	{
		long long k=a[i],sum=1;
		char r[100005];
		while(k!=0)
		{
			
			if(k%2==0)
			{
				r[sum]='0';
			}
			else
			{
				r[sum]='1';
			}
			sum++;
			k-=k%2;
			k/=2;
			if(k==0)
			{
				break;
			}		
		}
		sum-=1;
		cout<<sum<<endl;
		for(int j=1;j<=sum;j++)
		{		
			s[i][j]=r[sum-j+1];
		}
	}
	long long dp[n+1];
	dp[1]=a[n];
	cout<<a[n];
	return 0;
}
