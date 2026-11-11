#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[200007]{};
char c[200007]{};

long long sum;

int main()
{
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin>>n;
	
	for(long long i=1;i<=n;i++)
	{
		
		cin>>a[i]>>c[i];
		sum+=a[i];
		
	}
	
	long long r=n;
	
	long long ans=0;
	
	for(long long l=1;l<=n;l++)
	{
		
		long long now=a[l];
		
		while(l<r)
		{
			
			if(a[r]<now)
			{
				
				if(c[r]!=c[l])
				{
					
					ans+=a[r];
					
				}
				
				now-=a[r];
				a[r]=0;
				r--;
				
			}
			else
			{
				
				if(c[r]!=c[l])
				{
					
					ans+=now;
					
				}
				
				a[r]-=now;
				break;
				
			}
			
		}
		
	}
	
	cout<<ans;
	
	return 0;
	
}
