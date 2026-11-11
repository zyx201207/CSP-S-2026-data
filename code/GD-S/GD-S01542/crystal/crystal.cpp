#include <iostream>
#include <algorithm>
#include <cstdint>
#include <vector>

#define repm(i, begin, end) for (indice i = (begin); i < indice(end); i += 1)
#define rep(i, n) repm(i, 0, n)

using namespace std;

using lld = int64_t;
using indice = int32_t;

template<class T>
using CR = const T&;

#ifdef MDEBUG
template<class... Args>
void debug(CR<Args>... arg) {
	int _[] = { (cerr << arg << ' ', 0)... };
	cerr << '\n';
}
#else
#define debug(...) ((void)0)
#endif

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	indice n; lld m;
	cin >> n >> m;
	
	vector<lld> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	
	indice l = 0;
	lld need = 0;
	
	indice ans = 0;
	
	repm(r, 1, n) {
		need += (r - l) * (a[r] - a[r-1]);
		
		while(need > m) {
			need -= a[r] - a[l];
			l += 1;
		}
		
		ans = max(ans, (r - l) + 1);
	}
	
	cout << ans << '\n';
	return 0;
}
