#include <iostream>
#include <algorithm>
#include <cstdint>
#include <vector>

#include <bitset>
#include <array>

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

constexpr indice K = 2e5+7;
using Bits = bitset<K>;

constexpr indice L = 32;
using Table = array<Bits, L>;

/*
bool dfs(indice n, int& ans, Bits cur, CR<Table> table, indice m) {
	//debug("dfs", p, ans);
	
	if ((indice)cur.count() < m) return false;
	if (n == 0) return true;
	
	const indice p = n - 1;
	
	//debug("try", p, 1);
	
	if (dfs(n - 1, ans, cur & table[p], table, m)) {
		//debug(p, "1 ok");
		ans |= (1 << p);
		return true;
	}
	
	//debug("try", p, 0);
	return dfs(n - 1, ans, cur, table, m);
}
*/

/*
#include <stack>
static stack<Bits> dfsS;

bool dfs_s(indice n, int& ans, CR<Table> table, indice m) {
	//debug("dfs", p, ans);
	const Bits& cur = dfsS.top();
	
	if ((indice)cur.count() < m) return false;
	if (n == 0) return true;
	
	const indice p = n - 1;
	
	//debug("try", p, 1);
	
	dfsS.push(cur & table[p]);
	
	if (dfs_s(n - 1, ans, table, m)) {
		//debug(p, "1 ok");
		ans |= (1 << p);
		return true;
	}
	
	dfsS.pop();
	
	//debug("try", p, 0);
	return dfs_s(n - 1, ans, table, m);
}
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	indice n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	
	indice l = 32;
	
	{
		int ora = 0;
		
		rep(i, n) {
			ora |= a[i];
		}
		
		if (ora == 0) {
			cout << "0\n";
			return 0;
		}
		
		l = 32 - __builtin_clz(ora);
	}
	
	//debug("l", l);
	
	Table table {};
	
	rep(k, L) {
		rep(i, n) {
			table[k].set(i, a[i] & (1 << k));
			//debug(k, i, table[k][i]);
		}
		
		//debug("cnt", k, table[k].count());
	}
	
	int ans = 0;
	
	Bits cur;
	
	rep(i, n) cur[i] = 1;
	
	/*
	dfs(l, ans, cur, table, m);
	*/
	
	//dfsS.push(cur);
	//dfs_s(l, ans, table, m);
	
	
	for (indice k = l; k-- > 0; ) {
		Bits nextb = cur & table[k];
		
		if (nextb.count() >= m) {
			cur = nextb;
			ans |= 1 << k;
		} 
	}
	
	cout << ans << '\n';
	return 0;
}
