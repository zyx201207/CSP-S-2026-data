#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define sizf(x) ((int)(x).size())
#define report(...) fprintf(stderr, __VA_ARGS__)

inline ll read(void) {
	ll x=0,f=1; int ch;
	while (!isdigit(ch=getchar())) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x*f;
}

bool Mst;

const int N = 2e6+5;
const ll inf = 2e18;
int n;
ll d, x[N];

int L[N], R[N];
int wayl[N], wayr[N];

void clearup(void) {
	for (int i = 0; i <= n + 3; i++) L[i] = R[i] = wayl[i] = wayr[i] = 0;
}

bool Med;

int main(void)
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int cid = read(); int test = read();
	while (test--) {
		clearup();
		n = read(); d = read();
		for (int i = 1; i <= n; i++) x[i] = read();

		x[0] = -inf; x[n + 1] = inf;
		
		L[0] = 0;
		for (int i = 1, ptr = 1; i <= n; i++) {
			while (ptr < i && x[i] - x[ptr] > d) ptr++;
			L[i] = ptr;
		}
		R[n + 1] = n + 1;
		for (int i = n, ptr = n; i >= 1; i--) {
			while (ptr > i && x[ptr] - x[i] > d) ptr--;
			R[i] = ptr;
		}
		
		auto isr = [&] (int x, int y) { return y == R[x]; }; // y isr of x
		auto isl = [&] (int x, int y) { return y == L[x]; };
		
		for (int i = 1; i <= n; i++) {
			wayl[i] = 1;
			if (L[i] != i && isr(L[i], i)) wayl[i] += wayl[L[i]];
			wayl[i] += max(0, L[i + 1] - L[i] - 1);
		}
		for (int i = n; i >= 1; i--) {
			wayr[i] = 1;
			if (R[i] != i && isl(R[i], i)) wayr[i] += wayr[R[i]];
			wayr[i] += max(0, R[i] - R[i - 1] - 1);
		}
		
		ll ans = 0;
		for (int i = 1; i < n; i++) {
			int l = L[i], r = R[i + 1];
			if (l == i || r == i + 1 || x[r] - x[l] <= d) continue;
			if (isl(r, i) && isr(l, i + 1)) ans += 1ll * wayl[l] * wayr[r];
			
			int le1 = max(R[i - 1] + 1, i + 2);
			int ri1 = min(R[i + 1] - 1, R[i]);

			int le2 = max(L[i + 1], L[i] + 1);
			int ri2 = min(L[i + 2] - 1, i - 1);

			int len1 = max(ri1 - le1 + 1, 0), len2 = max(ri2 - le2 + 1, 0);
			if (isr(l, i + 1)) {
				ans += 1ll * len1 * wayl[l];
			}
			if (isl(r, i)) {
				ans += 1ll * len2 * wayr[r];
			}
			
			ans += 1ll * len1 * len2;
//			printf("i=%d ans=%lld\n", i, ans);
		}
		printf("%lld\n", ans);
	}
	

	report("Mem : %lf MB\n", abs(&Med - &Mst) / 1024.0 / 1024.0);
	report("Time: %lf s\n", 1.0 * clock() / CLOCKS_PER_SEC);
	return 0;
}
