#include<bits/stdc++.h>
using namespace std;
long long n,a[1000001],sum,p,k=1;
char s[1000001],ss[1000000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		for(long long j=sum+1;j<=a[i]+sum;j++)ss[j]=s[i];
		sum+=a[i];
	}
	if(sum%2==0)
	{
		for(long long i=1;i<=sum/2;i++)
		{
			if(ss[sum/2-(i-1)]==ss[sum/2+i])p++;
		}
		cout<<sum/2-p/2;
	}
	else 
	{
		for(long long i=1;i<=sum/2;i++)
		{
			if(ss[sum/2-(i-1)]==ss[sum/2+i+1])p++;
		}
		cout<<sum/2-p;
	}
	return 0;
}
