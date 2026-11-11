#include <iostream>
using namespace std;
long long n,m,cnt[300006];
int mn(long long a[500006],long long k)
{
	
	long long b[500006]={0},j=1;
	for(long long i=1;i<k;i++)
	{
		bool sb=false;
		for(long long l=1;l<=j;l++)
		{
			if(b[l]==a[i] || sb)
			{
				b[l]={};
				sb=true;
			}
		}
		b[j]=a[i];
		j++;
	} 
	for(long long f=1;f<=j;f++)
	{
		cnt[b[f]]++;
	}
	return 0;
} 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long a[n+5];
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long c[500006],k=1;
		for(int j=i;j<=n;j++)
		{
			c[k]=a[j];
			k++;
		}
		mn(c,k);
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
}
