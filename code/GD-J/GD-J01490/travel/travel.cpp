#include <iostream>
#include <algorithm>
#include <cstdint>
#include <vector>
#include <string>

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
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	indice c1, c2;
	
	int q1, q2;
	char p1, p2;
	
	cin >> c1 >> q1 >> p1;
	cin >> c2 >> q2 >> p2;
	
	if (p1 > p2) swap(p1, p2);
	
	bool a1 = ( c1 == c2 );
	bool a2 = ( a1 && q1 == q2 );
	bool a3 = ( a2 && ( (p1 < 'D') == (p2 < 'D') ) );
	bool a4 = ( a3 && ( (p1 == 'D' && p2 == 'F') || (p1 + 1 == p2) ) );
	
	cout << a1 << a2 << a3 << a4 << '\n';
	return 0;
}
