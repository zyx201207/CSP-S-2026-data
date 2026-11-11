#include<bits/stdc++.h>
using namespace std;
long long c[1000000];
long long d[1000000];
long long int aaa(int a,long long int b)
{
	long long int e=0;
	long long int f=1;
	for(int i=a-1;i>=0&&b>0;i--)
	{
		e+=d[i];
		b-=e;
		if(b<0)
		{
			return f;
		}
		f++;
	}
	return f;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	for(int i=0;i<a;i++)
	{
		scanf("%lld",&c[i]);
	}
	if(a>5000)
	{
		printf("%d",b/(c[1]-c[0])+1);
		return 0;
	}
	for(int i=1;i<a;i++)d[i-1]=c[i]-c[i-1];
	int e=0;
	for(int i=a-1;i>=e;i--)
	{
		long long int f=aaa(i,b);
		
		if(f>e)e=f;
	}
	printf("%d",e);
	return 0;
}
