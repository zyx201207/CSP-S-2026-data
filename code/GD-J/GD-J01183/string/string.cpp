#include<bits/stdc++.h>
using namespace std;
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n+5];
	char c[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1])
		{
			a[i-1]+=a[i];
			i--;
			n--;
		}
		
	}
	for(int i=1;i<=n/2;i++)
	{
		if(c[i]==c[n-i+1])
		{
			if(a[i]==a[n-i+1])
			{
				continue;
			}
			else{
				if(a[i]>a[n-i+1])
				{
					
					sum+=a[i]-a[n-i+1];
					a[n-i]-=a[i]-a[n-i+1];
					
				}
				else{
					
					sum+=a[n-i+1]-a[i];
					a[i+1]-=a[n-i+1]-a[i];
				}
			}
		}
		else{
				if(a[i]>a[n-i+1])
				{
						
					sum+=a[n-i+1];
					if(c[i]==c[n-i]){
						a[n-i]-=a[i]-a[n-i+1];
					}
					else{
						sum+=a[i]-a[n-i+1];
						a[n-i]-=a[i]-a[n-i+1];
					}
					
				}
				else{
					sum+=a[i];
					if(c[n-i+1]==c[i+1]){
						a[i+1]-=a[n-i+1]-a[i];
					}
					else{
						sum+=a[n-i+1]-a[i];
						a[i+1]-=a[n-i+1]-a[i];
					}
				}
		}
	}
	
	cout<<sum;
	return 0;
}
