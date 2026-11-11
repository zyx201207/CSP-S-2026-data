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
using BoolVec = vector<char>; 

/*
#include <stack>

// O(n^2)
IdxVec brute(indice m, vector<int>& a) {
	const indice n = a.size();
	
	IdxVec ans(m, 0);
	
	rep(l, n) {
		stack<indice> st;
		BoolVec instack(m, false);
		
		repm(i, l, n) {
			indice t = a[i];
			
			if (!instack[t]) {
				st.push(t);
				instack[t] = true;
				continue;
			}
			
			while(st.top() != t) {
				instack[st.top()] = false;
				st.pop();
			}
		}
		
		rep(i, m) {
			if (instack[i])
				ans[i] += 1;
		}
	}
	
	return ans;
}

*/

/*
// O(n^2)
IdxVec solve1(indice m, vector<int>& a) {
	const indice n = a.size();
	
	IdxVec last(m, -1);
	
	rep(i, n) {
		last[a[i]] = i;
	}
	
	IdxVec ans(m, 0);
	
	rep(l, n) {
		//debug("solving", l, n);
		indice p = l;
		
		while(p < n) {
			//debug("vis", p, a[p]+1);
			
			ans[a[p]] += 1;
			p = last[a[p]] + 1;
		}
	}
	
	return ans;
}
*/

#include <queue>

// O(m)
IdxVec solve2(indice m, vector<int>& a) {
	const indice n = a.size();
	
	IdxVec last(m, -1);
	
	rep(i, n) {
		last[a[i]] = i;
	}
	
	IdxVec adj(n, 0), deg(n, 0);
	
	rep(i, n) {
		adj[i] = last[a[i]] + 1;
		deg[adj[i]] += 1;
	}
	
	queue<indice> q;
	
	rep(i, n) {
		if (deg[i] == 0) {
			q.push(i);
		}
	}
	
	IdxVec ans(m, 0);
	IdxVec cnts(n, 1);
	
	while(!q.empty()) {
		indice u = q.front(); q.pop();
		
		ans[a[u]] += cnts[u];
		
		indice v = adj[u];
		if (v == n) continue;
		
		deg[v] -= 1;
		cnts[v] += cnts[u];
		
		if (deg[v] == 0) {
			q.push(v);
		}
	}
	
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	indice n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i] -= 1;
	}
	
	auto ans = solve2(m, a);
	
	rep(i, m) {
		cout << ans[i] << ' ';
	}
	
	cout << '\n';
	return 0;
}
