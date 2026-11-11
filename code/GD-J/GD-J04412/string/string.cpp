#include<bits/stdc++.h>
#define ll long long
#define For(i, x, y) for(int i = x; i <= y; i++)
#define RFor(i, x, y) for(int i = x; i >= y; i--)
using namespace std;
const int N = 2e5+5;
int n;
int a[N], cnt;
ll len, st[N], ed[N];
char c[N];
ll ans;
int main()
{
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
	scanf("%d",&n);
	For(i, 1, n)
	{
		scanf("%d %c",&a[i], &c[i]);
		st[i] = ed[i-1]+1;
		ed[i] = st[i]+a[i]-1;
		len += a[i];
	}
	For(i, 1, n)
	{
		ll minn = len-ed[i]+1;
		ll maxx = len-st[i]+1;
//		printf("%lld %lld\n",minn, maxx); 
		int l = (int)(upper_bound(st+1, st+1+n, minn)-st-1);
		int r = (int)(lower_bound(ed+1, ed+1+n, maxx)-ed);
//		printf("%d %d %d\n",i, l, r);
		For(j, l, r)
			ans += (c[i] != c[j])*(min(maxx, ed[j])-max(minn, st[j])+1);
	}
	printf("%lld",ans/2);
	return 0;
}
//	For(i, 1, n)
//		printf("%d%c\n",a[i], c[i]);
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
