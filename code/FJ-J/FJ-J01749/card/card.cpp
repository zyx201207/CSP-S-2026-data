#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
const int N=5e5+5, M=3e5+5;

int n, m;
int a[N], b[M];
bool vis[M];

inline void sol (int k) {
	memset (vis, 0, sizeof vis);
	stack <int> s;
	for (int i=k; i<=n; i++) {
		if (vis[a[i]]) {
			while (s.top ()!=a[i]) {
				vis[s.top ()]=0;
				s.pop ();
			}
		} else {
			s.push (a[i]);
			vis[a[i]]=1;
		}
	}
	while (!s.empty ()) {
		b[s.top ()]++;
		s.pop ();
	}
}

int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	ios::sync_with_stdio (0), cin.tie (0);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>a[i];
	for (int i=1; i<=n; i++) sol (i);
	for (int i=1; i<=m; i++) cout<<b[i]<<' ';
	return 0;
}
//CSP-J RP++
//CCF, you're my dad.
