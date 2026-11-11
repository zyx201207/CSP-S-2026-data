#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct POINT
{
	ll len;
	char c;
}p[200007];
ll n, cnt, num, l, r, ans;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i ++)
	{
		scanf("%lld", &p[i].len);
		cin >> p[i].c;
		cnt += p[i].len;
	}
	if (n == 1) 
	{
		printf("0");
		return 0;
	}
	
	num = cnt / 2;
	l = 1;
	r = n;
	while (l < r)
	{
		if (!p[l].len) l ++;
		if (!p[r].len) r --;
		if (p[l].c != p[r].c) ans ++;
		p[l].len --;
		p[r].len --;
	}
	printf ("%lld", ans);

// 	l = 1, r = n;
//	while(l < r)
//	{
//		if(p[l].len > p[r].len && p[l].c != p[r].c)
//		{
//			ans += p[l].len - p[r].len;
//			p[l].len -= p[r].len;
//			r --;
//		}
//		else if(p[l].len < p[r].len && p[l].c != p[r].c)
//		{
//			ans += p[r].len - p[l].len;
//			p[r].len -= p[l].len;
//			l ++;
//		}
//		else if(p[l].len > p[r].len && p[l].c == p[r].c)
//		{
//			p[l].len -= p[r].len;
//			r --;
//		}
//		else if(p[l].len < p[r].len && p[l].c == p[r].c)
//		{
//			p[r].len -= p[l].len;
//			l ++;
//		}
//		else if(p[l].len == p[r].len && p[l].c != p[r].c)
//		{
//			ans += p[l].len;
//			l ++;
//			r --;
//		}
//		else 
//		{
//			l ++;
//			r --;
//		}
//	}
//	printf("%lld", ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

