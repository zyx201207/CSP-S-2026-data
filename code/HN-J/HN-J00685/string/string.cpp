#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,d;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&b[i]);
	}
	for(int i=1;i<=(n+1)/2;i++)
	{
		int j=n-i+1;
		if(i==j)
		{
			break;
		}
		if(a[i]>a[j])
		{
			long long c=a[i];
			if(b[i]!=b[j])
			{
				sum+=a[j];
			}
			b[j]=b[i];
			c-=a[j];
			for(;c>0;)
			{
				if(a[j-1]<=c)
				{
					if(b[j-1]!=b[i])
					{
						sum+=a[j-1];
					}
					c-=a[j-1];
					b[j-1]=b[i];
					a[j-1]+=a[j];
					j--;
					n--;
				}
				else
				{
					if(b[j-1]!=b[i])
					{
						sum+=c;
					}
					a[j-1]-=c;
					a[j]+=c;
					c=0;
				}
			}
		}
		else if(a[i]<a[j])
		{
			int c=a[j];
			if(b[i]!=b[j])
			{
				sum+=a[i];
			}
			b[i]=b[j];
			c-=a[i];
			for(;c>0;)
			{
				if(a[i+1]<=c)
				{
					if(b[i+1]!=b[j])
					{
						sum+=a[i+1];
					}
					c-=a[i+1];
					b[i+1]=b[j];
					a[i+1]+=a[i];
					i++;
				}
				else
				{
					if(b[i+1]!=b[i])
					{
						sum+=c;
					}
					a[i+1]-=c;
					a[i]+=c;
					c=0;
				}
			}
		}
		else
		{
			if(b[i]!=b[j])
			{
				sum+=a[i];
			}
			b[j]=b[i];
		}
	}
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
