#include <bits/stdc++.h> //1
using namespace std;
#define int long long

#define rec card__name__0

const int N=5e5,M=3e5;
int a[N+105];
int lst[M+105];
int cnt[M+105];

signed main ()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	scanf("%lld %lld",&n,&m);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
		lst[a[i]]=i;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=i; j<=n; j=lst[a[j]]+1)
		{
			cnt[a[j]]++;
		}
	}
	for (int i=1; i<=m; i++)
	{
		printf("%lld ",cnt[i]);
	}
	return 0;
}

/*
4 3
1 2 1 3

3 1 4
*/

/*
10 3
3 1 2 1 3 2 3 1 2 1

10 3 3
*/
