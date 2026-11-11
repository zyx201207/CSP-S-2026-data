#include<bits/stdc++.h>
using namespace std;
long long a,b,s[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	bool f=0;
	long long h=0;
	for(int i=1;i<=a;i++) 
	{
		cin>>s[i];
		if(i==2)
		{
			h=s[i]-s[i-1];
		}
		if(i>=3) 
		{
			if(h!=s[i]-s[i-1]) f=1;
		}
	}
	if(f==0)
	{
		long long g=s[2]-s[1];
		long long ans=0,sum=0;
		for(int i=1;i<=a;i++)
		{
			ans+=i*g;
			sum++;
			if(ans>b) 
			{
				cout<<sum;
				return 0;
			}
			if(ans==b) 
			{
				cout<<sum+1; 	
				return 0;
			}
		}
	}
	sort(s+1,s+1+a);
	long long ans=0,ansmax=0,sum=0,k=-0x3f3f3f;
	for(int i=2;i<=a;i++)
	{
		if(ans<=b)
		{
			sum++;
			ans+=(s[i]-s[i-1])*sum;	
		}
		if(ans>b)
		{
			for(int j=i-sum;j<=i;j++)
			{
				ans=ans-(s[i]-s[j]);
				sum--;
				if(ans<=b) break;
			}
		}
		if(sum+1>k) 
		{
			k=sum+1;
		} 
	}
	cout<<k;
	return 0;
} 
