#include<bits/stdc++.h>
using namespace std;
namespace IO {
	constexpr int bufsize = 230005;
	char buf[bufsize], *f1, *f2;
	char gtchar() {return f1 == f2 && (f2 = buf + fread(f1 = buf, 1, bufsize, stdin)) == buf? EOF: *f1++;}
	template<typename t> void read(t &ret)
	{
		int f = ret = 0;
		char ch = gtchar();
		while(!isdigit(ch)) f = ch == '-', ch = gtchar();
		while(isdigit(ch)) ret = ret * 10 + (ch ^ 48), ch = gtchar();
		if(f) ret = -ret;
	}
	template<typename t, typename ...T> void read(t &a, T &...b) {read(a), read(b...);}
} using IO::read;
typedef long long ll;
constexpr int maxn = 2e6 + 5;
int testid, T, n, f[maxn];
ll a[maxn], d;
void solve1()// n^2
{
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		deque<pair<int, int> > q = {{i, 0}}; f[i] = 1;
		for(int j = i + 1; j <= n; j++)
		{
			while(q.size() && a[j] - a[q[0].first] > d) q.pop_front();
			if(q.empty()) break;
			f[j] = 0;
			for(int k = 0; k <= 3 && k < q.size() && q[0].second == q[k].second; k++) f[j] += f[q[k].first];
			f[j] = min(f[j], 3);
			if(f[j] == 2) ++ans;
			int mn = q[0].second + 1;
			while(q.size() && q.back().second > mn) q.pop_back();
			q.push_back({j, mn});
		}
	}
	printf("%d\n", ans);
}
int pre[maxn], suf[maxn];
void solve()
{
	read(n, d);
	for(int i = 1; i <= n; i++) read(a[i]);
	if(testid <= 10) return solve1();
	pre[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(a[i] - a[i - 1] <= d && (i == n || a[i + 1] - a[i - 1] > d))
			pre[i] = pre[i - 1];
		pre[i]++;
	}
	suf[n] = 1;
	for(int i = n - 1; i; i--)
	{
		if(a[i + 1] - a[i] <= d && (i == 1 || a[i + 1] - a[i - 1] > d))
			suf[i] = suf[i + 1];
		suf[i]++;
	}
	ll ans = 0;
	for(int i = 1; i + 3 <= n; i++)
	{
		ll d1 = a[i + 1] - a[i], d2 = a[i + 2] - a[i + 1], d3 = a[i + 3] - a[i + 2];
		if(d1 + d2 <= d && d2 + d3 <= d && d1 + d2 + d3 > d) ans += 1ll * pre[i] * suf[i + 3];//, printf("%d %d\n", i, i + 3);
	}
	printf("%lld\n", ans);
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	read(testid, T);
	while(T--) solve();
	return 0;
}