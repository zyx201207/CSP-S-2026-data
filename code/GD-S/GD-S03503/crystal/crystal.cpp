#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i = 1 ; i <= n ; i ++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	long long num = 1;
	while(m!=0)
	{
		while(a[num] == a[num+1])num ++;
		if(num > m) 
		{
			break;
		}
		for(long long i = 1 ; i <= num ; i ++) 
		{
			a[i] ++ ;
			m--;
		}
		while(a[num] == a[num+1])num ++;
	}
	printf("%lld",num);
}
