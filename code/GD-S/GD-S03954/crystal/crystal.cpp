#include<bits/stdc++.h>
#define ll long long
#define For(i, x, y) for(int i = x; i <= y; i++)
#define RFor(i, x, y) for(int i = x; i >= y; i--)
using namespace std;
const int N = 5e5+5; 
int n;
ll m;
ll a[N];
ll cha[N], s[N];
int now = 1, maxx = 1;
int main()
{
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
	scanf("%d%lld",&n, &m);
	For(i, 1, n)
		scanf("%lld",&a[i]);
	sort(a+1, a+1+n);
	For(i, 1, n-1)
	{
		cha[i] = a[i+1]-a[i];
		s[i] = s[i-1]+cha[i];
	}
	For(i, 1, n-1)
	{
		while(now > 0 && m < cha[i]*now)
		{
			m += s[i-1]-s[i-now];
			now--;
		}
		if(m >= cha[i]*now)
		{
			m -= cha[i]*now;
			now++;
		}
		maxx = max(maxx, now);
	}
	printf("%d",maxx);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
