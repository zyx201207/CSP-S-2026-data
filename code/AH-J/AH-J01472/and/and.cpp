#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a, ans;
struct node
{
	long long x, l, r;
	int y;
}e[1080000];
int last = 2;
void Add(long long x)
{
	long long xx = x;
	long long t = 1073741824;
	long long u = 1;
	while(t)
	{
		e[u].y ++;
//		cout << e[u].y << '\n';
		if(x >= t)
		{
//			cout << xx << ' ' << t << '\n';
			x -= t;
			if(e[u].r == 0)
				e[u].r = last ++;
			u = e[u].r;
//			cout << 1;
		}
		else
		{
			if(e[u].l == 0)
				e[u].l = last ++;
			u = e[u].l;
//			cout << 0;
		}
		t >>= 1;
	}
//	cout << '\n';
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		scanf("%lld", &a);
		Add(a);
	}
	long long u = 1, t = 1073741824;
	while(u)
	{
//		cout << u << ' ' << e[u].x << ' ' << e[e[u].r].y << ' ' << e[u].l << ' ' << e[u].r << '\n';
		if(e[u].r && e[e[u].r].y >= m)
		{
//			cout << 1;
			ans += t;
			u = e[u].r;
		}
		else
		{
//			cout << 0;
			u = e[u].l;
		}
		t >>= 1;
	}
	cout << ans;
	return 0;
}
