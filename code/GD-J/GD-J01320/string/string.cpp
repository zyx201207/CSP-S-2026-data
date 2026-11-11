#include<iostream>
using namespace std;
struct aaa
{
	long long int a;
	char b;	
};
aaa a[100000000]={};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int b;
	scanf("%d",&b);
	for(int i=0;i<b;i++)
	{
		long long int c;char d;
		scanf("%lld",&c);
		scanf(" %c",&d);
		if(i)
		{
			if(d==a[i-1].b)
			{
				a[i-1].a+=c;
				i--;
				b--;
				continue;
			}
		}
		a[i].a=c;a[i].b=d;
	}
	long long int d=0;
	int c=0;
	b--;
	while(c<=b)
	{
		if(a[b].a>a[c].a)
		{
			if(a[b].b!=a[c].b)d+=a[c].a;
			a[b].a-=a[c].a;
			c++;
			continue;	
		}
		if(a[b].a==a[c].a)
		{
			if(a[b].b!=a[c].b)d+=a[c].a;
			c++;
			b--;
			continue;	
		}
		if(a[b].a<a[c].a)
		{
			if(a[b].b!=a[c].b)d+=a[b].a;
			a[c].a-=a[b].a;
			b--;
			continue;	
		}
	}
	printf("%lld",d);
	return 0;
}
