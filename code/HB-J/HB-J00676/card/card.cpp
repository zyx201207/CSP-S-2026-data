#include <iostream>
#include <cstring>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 5e5 + 5;
const int M = 3e5 + 5;

int n, m, a[N];
int tot, vec[N];
int ans[M];
bool vis[M];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	F(i, 1, n) cin >> a[i];
	
	F(i, 1, n) {
		tot = 0, memset(vis, 0, sizeof vis);
		
		F(j, i, n) {
			bool fl = 0;
			int pos;
			
			F(k, 1, tot)
				if (vec[k] == a[j]) {
					fl = 1, pos = k;
					break ;
				}
			if (fl) tot = pos;
			else vec[++tot] = a[j];
		}
		
		F(j, 1, tot) {
			if (vis[vec[j]]) continue ;
			ans[vec[j]]++, vis[vec[j]] = 1;
		}
	}
	
	F(i, 1, m) cout << ans[i] << ' ';
	
	return 0;
}
