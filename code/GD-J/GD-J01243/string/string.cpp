#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a[200005]={};
	char s[200005];
	long long n;
	cin>>n;
	if(n==1) 
	{
		cout<<0;
		return 0;
	}
	for(int i  = 0;i<=n-1;i++)
	{
		cin>>a[i];
		cin>>s[i];
	}
	long long ans=0;
	for(long long i = 0;i<=(n-1);i++) 
	{					
			for(int j = 0;j<n;j++)
			{
				if(a[i]<=0)
				{
					break;
				}
				else if(s[i]!=s[n-1-j])
				{
					ans=ans+min(a[n-1-j],a[i]);
					if(a[i]>a[n-1-j]) 
					{
						a[i]-=a[n-1-j];
						a[n-1-j]=0;
					}						
					else {
						a[n-1-j]-=a[i];
						a[i]=0;
					}
				}
				else if(s[i]==s[n-1-j])
				{
					if(a[i]>a[n-1-j]) 
					{
						a[i]-=a[n-1-j];
						a[n-1-j]=0;
					}						
					else {
						a[n-1-j]-=a[i];
						a[i]=0;
					}
				}	
			}
	}
	cout<<ans;
	return 0;
 } 
