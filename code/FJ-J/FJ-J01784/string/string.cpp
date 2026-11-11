#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n;
LL ans;
struct bin{
	LL k;
	char x;
}a[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		char s[10];
		scanf("%lld%s",&a[i].k,s);
		a[i].x=s[0];
	}
	LL i=1,j=n;
	while(i<j)
	{
		if(a[i].x!=a[j].x)
		{
			if(a[i].k<a[j].k)
			{
				ans+=a[i].k;
				a[j].k-=a[i].k;
				i++;
			}
			else if(a[i].k==a[j].k) 
			{
				ans+=a[i].k;
				i++,j--;
			}
			else 
			{
				ans+=a[j].k;
				a[i].k-=a[j].k;
				j--;
			}
		}
		else 
		{
			if(a[i].k==a[j].k) i++,j--;
			else if(a[i].k<a[j].k) a[j].k-=a[i].k,i++;
			else a[i].k-=a[j].k,j--; 
		}
	}
	printf("%lld",ans);
	return 0; 
}
/*
6
5 a
7 c
3 a
2 b
8 d
6 c
*/
