#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long b[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,sum;
	sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i-1;j++)
		{
			if(a[i]==a[j])
			{
				for(int t=j;t<i;t++)
				{
					a[t]=0;
				}
			}	
		}
		for(int x=1;x<=i;++x)
			{
				if(a[x]>0)
				{
					sum=sum+1;
				}
			}
			b[sum]=b[sum]+1;
			sum=0;
	}
	for(int i=0;i<m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
 } 
