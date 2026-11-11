#include<bits/stdc++.h>
using namespace std;
long long a[1000000005];
long long b[1000000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	long long u=1;
	for(long long i=1;i<=n;i++)
	{
		
		long long d;
		char s;
		cin>>d>>s;
		
		for(long long i=1;i<=d;i++)
		{
			a[u]=s;
			u++;
		}
	}
	
	for(long long i=1;i<=u;i++)
	{
		b[i]=a[u-i];
		
	}
	long long sum=0;

	for(long long i=1,j=1;i<=u/2-1;i++,j++)
	{
		if(a[i]!=b[j]) sum++;
	}	
	cout<<sum;
	return 0;
 } 
