#include <bits/stdc++.h>
#define scan(x) scanf("%lld", &x)
#define scan2(x, y) scanf("%lld%lld", &x, &y)
#define scan3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
using namespace std;
void scans(string& s) {s.clear();char in=getchar();while(in=='\n'||in==' '||in=='\t'||in=='\r')if(in==EOF)return;else in=getchar();while(in!='\n'&&in!=' '&&in!='\t'&&in!='\r' && in!=EOF)s+=in,in=getchar();}
using LL = long long;
using ll = long long;
#define filename "and"
constexpr LL N = 1000100;

LL n, m, a[N];
bool flag = 1;
//bool cmp(const LL& x, const LL& y) { return __builtin_popcountll(x) > __builtin_popcountll(y); }
bool cmp(const LL& x, const LL& y) { return __builtin_popcountll(x) == __builtin_popcountll(y) ? (x & -x) > (y & -y) : __builtin_popcountll(x) > __builtin_popcountll(y); }
//bool cmp(const LL& x, const LL& y) { return (x & -x) > (y & -y); }
void solve() {
	scan2(n, m);
	for(LL i = 1; i <= n; i ++) scan(a[i]), flag &= (a[i] == a[i - 1] + 1 || i == 1);
	sort(a + 1, a + 1 + n, cmp);
	if(flag) { printf("%lld\n", 3ll << LL(log2(a[1]) - 1)); return ; }
//	for(LL i = 1; i <= m; i ++) printf("%lld ", a[i]);
	LL ans = a[1];
	for(LL i = 2; i <= m; i ++) ans &= a[i];
	printf("%lld\n", ans);
}

int main() {
	freopen(filename  ".in", "r",  stdin);
	freopen(filename ".out", "w", stdout);

//	LL t; scan(t); while(t --)
	solve();

	fclose(stdin);
	fclose(stdout);
	return 0;
}

