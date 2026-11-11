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

const int N = 5e5+5;
int n;
ll m, a[N], s[N];

bool Med;

int main(void)
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read(); m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = a[i] + s[i - 1];
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i;
		while (l < r) {
			int mid = (l + r) / 2;
			if ((i - mid) * a[i] - (s[i] - s[mid]) <= m) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - l);
	}
	
	printf("%d\n", ans);
	
	report("Mem : %lf MB\n", abs(&Med - &Mst) / 1024.0 / 1024.0);
	report("Time: %lf s\n", 1.0 * clock() / CLOCKS_PER_SEC);
	return 0;
}
