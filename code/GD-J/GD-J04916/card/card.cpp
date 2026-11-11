#include<bits/stdc++.h>
using  namespace std;
long long a[500000],cnt[500000],b[500000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,card;
	cin>>n>>m;
	for(long long i=0;i<=n-1;i++) 
	{
		cin>>card;
		b[i]=card;
		a[i]=card;
	}
	for(long long i=0;i<=n-1;i++)
	{
		for(long long y=0;y<=n-1;y++)
		{
			for(long long j=y+1;j<=n-1;j++)
			{
				if(a[j]==a[y])
				{
					for(long long z=y;z<j;z++)
					{
						a[z]=0;
					}
					break;
				} 
			}
		}		
		for(long long j=i;j<n;j++)
		{
			if(a[j]!=0)
			{
				cnt[a[j]-1]++;
			}
			a[j]=b[j];
		}
	}
	for(long long j=0;j<m;j++)
	{
		if(j==1)
			cout<<cnt[j]+1<<' ';
		else
			cout<<cnt[j]<<' ';
	}	
}
