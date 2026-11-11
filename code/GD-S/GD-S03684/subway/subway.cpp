#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
const int MAXN = 500005;
long long c , n , m , d , q;
long long t1[MAXN];
int a[MAXN] , t2[MAXN];
int main()
{
//	freopen("subway.in" , "r" , stdin);
//	freopen("subway.out" , "w" , stdout);
	scanf("%lld%lld%lld%lld%lld" , &c , &n , &m , &d , &q);
	for(int i = 1;i <= m;i++) scanf("%lld" , &t1[i]);
	for(int i = 1;i <= n;i++)
	{
		long long x;
		scanf("%lld" , &x);
		for(int j = 1;j <= x;j++) scanf("%d%d" , &a[i] , &t2[i]);
	}
	while(q--)
	{
		
	}
	return 0;
}
