#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
long long n;
long long a[200010];
char c[200010];
long long j1[200010];
char j2[200010];
long long ans=0;
long long k,i;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>a[i]>>c[i];
		
	}
	k=n-1;
	while (k!=i&&k>i)
	{
		if (a[i]==a[k])
		{
			if (c[i]!=c[k])
			{
				ans+=a[i];
				k--;
				i++;
			}
		}
		else//a[i]!=a[k]
		{
			if (c[i]==c[k])
			{
				if (a[i]>a[k])
				{
					a[i]-=a[k];
					a[k]=0;
					k--;
				}
				else if (a[i]<a[k])
				{
					a[k]-=a[i];
					a[i]=0;
					i++;
				}
			}
			else if (c[i]!=c[k])
			{
				if (a[i]>a[k])
				{
					ans+=a[k];
					a[i]-=a[k];
					a[k]=0;
					k--;
				}
				else if (a[i]<a[k])
				{
					ans+=a[i];
					a[k]-=a[i];
					a[i]=0;
					i++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
 } 
