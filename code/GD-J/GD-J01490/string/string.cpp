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

using IdxVec = vector<indice>;
using CharVec = vector<char>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	indice n;
	cin >> n;
	
	IdxVec cnts(n);
	CharVec chs(n);
	
	rep(i, n) {
		cin >> cnts[i] >> chs[i];
	}
	
	IdxVec rcnts(cnts.crbegin(), cnts.crend());
	CharVec rchs(chs.crbegin(), chs.crend());
	
	indice i = 0, j = 0;
	lld li = 0, lj = 0;
	
	lld ans = 0;
	
	while(i + j < n - 1) {
		lld ri = li + cnts[i];
		lld rj = lj + rcnts[j];
		
		//debug(i, j, li, ri, lj, rj);
		
		// clen >= 0
		lld clen = min(ri, rj) - max(li, lj);
		
		if (chs[i] != rchs[j]) {
			ans += clen;
		}
		
		if (ri < rj) {
			li = ri; i += 1;
		} else {
			lj = rj; j += 1;
		}
	}
	
	cout << ans << '\n'; 
	return 0;
}
