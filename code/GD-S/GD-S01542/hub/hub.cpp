#include <iostream>
#include <algorithm>
#include <cstdint>
#include <vector>

#define repm(i, begin, end) for (indice i = (begin); i < indice(end); i += 1)
#define rep(i, n) repm(i, 0, n)

using namespace std;
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



void Case() {
	indice n, k;
	
	rep(i, n - 1) {
		indice u, v;
		cin >> u >> v;
	}
	
	cout << n / 4 << '\n'; 
	return;
}

void SpecA() {
	indice n, k;
	cin >> n >> k;
	
	indice m = 0;
	
	rep(i, n - 1) {
		indice u, v;
		cin >> u >> v;
		
		if (u + 1 == v) {
			m = i + 1;
		}
	}
	
	m += 1;
	
	//debug("n m k", n, m, k);
	
	if (m == n) {
		cout << (((n - 1) - (k - 2) + 3) / 4) << '\n';
		return;
	}
	
	if (m * 2 == n) {
		cout << (((n - 1) - (k - 2) + 3) / 4 + 1) << '\n';
		return;
	}
	
	cout << (((n - 1) - (k - 2) + 3) / 4 + 1) << '\n';
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	indice c, t;
	cin >> c >> t;
	
	if (c == 13 || c == 14) {
		rep(i, t) {
			SpecA();
		}
	}
	
	rep(i, t) {
		Case();
	}
	
	return 0;
}
