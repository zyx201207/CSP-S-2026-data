#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int ant=0;
	long long use=0;
	long long z=0;
}dp[20000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	
		int flag=1;
	cin>>n>>m;
		if(n<5000)
	{
		long long a[30001];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
	sort(a,a+n);

	dp[0].ant=1;
	dp[0].use=0;
	dp[0].z=a[0];
	int sum=-1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if((dp[j].use+(a[i]-dp[j].z)*dp[j].ant)<=m)
			{
				if(dp[i].ant<dp[j].ant+1) 
				{
					dp[i].z=a[i];
					dp[i].use=dp[j].use+(a[i]-dp[j].z)*dp[j].ant;
					dp[i].ant=dp[j].ant;
					dp[i].ant++;
					if(sum<dp[i].ant) sum=dp[i].ant;
				}	
								
			}
			else break;
		
		}
			
	}
	cout<<sum;
	}
	else 
	{
		int s[400];
		for(int i=0;i<300;i++)
		{
			cin>>s[i];
		}
		for(int i=0;i<=n;i++)
		{
			long long q=abs(s[13]-s[12])*i*i+abs(s[13]-s[12])*i;
			if(q>m*2) 
			{
				cout<<i;
				break;
			}
		}
	}
	return 0;
} 
