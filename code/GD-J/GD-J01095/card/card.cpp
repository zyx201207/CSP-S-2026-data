#include <bits/stdc++.h>
#define scan(x) scanf("%lld", &x)
#define scan2(x, y) scanf("%lld%lld", &x, &y)
#define scan3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
using namespace std;
void scans(string& s) {s.clear();char in=getchar();while(in=='\n'||in==' '||in=='\t'||in=='\r')if(in==EOF)return;else in=getchar();while(in!='\n'&&in!=' '&&in!='\t'&&in!='\r' && in!=EOF)s+=in,in=getchar();}
using LL = long long;
using ll = long long;
#define filename "card"
constexpr LL N = 5e5 + 10;

LL n, m, a[N], b[N], cnt, t[N];

void solve() {
	scan2(n, m);
	for(LL i = 1; i <= n; i ++) scan(a[i]);
	for(LL i = 1; i <= n; i ++) {
		memset(b, 0, sizeof b);
		vector <LL> vt;
		for(LL j = i; j <= n; j ++) {
			if(b[a[j]] && vt[b[a[j]] - 1] != a[j]) b[a[j]] = 0;
			if(!b[a[j]]) vt.push_back(a[j]), b[a[j]] = vt.size();
			else {
				for(LL k = vt.size(), e = b[a[j]] - 1; k > e + 1; k --) b[vt[k - 1]] = 0;
				vt.erase(vt.begin() + b[a[j]], vt.end());
			}
		}
		for(LL j = 1; j <= m; j ++) t[j] += !!b[j];
	}
	for(LL i = 1; i <= m; i ++) printf(i == m ? "%lld" : "%lld ", t[i]); puts("");
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

