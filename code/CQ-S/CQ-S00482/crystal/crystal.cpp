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
constexpr int maxn = 5e5 + 5;
int n, ans;
ll m, a[maxn];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	read(n, m);
	for(int i = 1; i <= n; i++) read(a[i]);
	sort(a + 1, a + 1 + n);
	ll tot = 0;
	for(int r = 1, l = 1; r <= n; r++)
	{
		while(tot > m) tot -= a[r] - a[l++];
		ans = max(r - l + 1, ans);
		if(r < n) tot += (r - l + 1) * (a[r + 1] - a[r]);
	}
	printf("%d\n", ans);
	return 0;
}