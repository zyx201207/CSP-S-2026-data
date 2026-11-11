#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[100000];
long long b[100000];
long long c[100000];
int main()
{
		freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	
	
	for(long long p=1;p<=n;p++)
	{
			long long k=1;
	for(long long i=p;i<=n;i++)
	{
		c[k]=a[i];
		for(long long j=1;j<=k;j++)
		{
			if(j!=i&&c[j]==a[i])
			{
				for(long long q=j;q<=k;q++)
				{
					c[q]=0;
				}
				k=j;
				c[k]=a[i];
			}
		}
			k++;
			}
			
			
			
//			cout<<endl<<endl;
//			for(int o=1;o<=k;o++)
//			{
//				cout<<c[o]<<" ";
//			}
//			cout<<endl<<endl;
//			
			
			
		for(long long j=1;j<=m;j++)
		{
			for(long long q=1;q<=k;q++)
			{
				if(c[q]==j)
				{
					b[j]++;
				}
			}
		}
		for(long long i=1;i<=k+5;i++)
		{
			c[i]=0;
		}
	}

	

	
	
	
	for(long long i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
}
