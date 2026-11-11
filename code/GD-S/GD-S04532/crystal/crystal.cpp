#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;

int n, ans=0;
ll a[N], m, sum=0;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for (int i=1; i<=n; i++) scanf("%lld", &a[i]);
	sort(a+1, a+1+n);
	
	int L=1;
	ll len=0;
	for (int i=1; i<=n; i++)
	{
		sum+=a[i], len++;
		while (a[i]*len-sum>m) sum-=a[L], L++, len--;
		
//		printf("%d %d %lld %lld\n", i, L, sum, len);
		ans=max(ans, i-L+1);
	}
	
	printf("%d", ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

4 3
1 3 4 5
*/
