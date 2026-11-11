#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 10;

ll c, t, n, d, x[N], f[N], g[N], s[N];
deque<int> q;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		ll ans = 0;
		for(int i = 1;i < n;i++){
			for(int j = 0;j <= n;j++){
				f[j] = 1e9, g[j] = s[j] = 0;
			}
			while(!q.empty()) q.pop_back();
			f[i] = 0, g[i] = 1, s[0] = 1;
			q.push_back(i);
			for(int j = i + 1;j <= n;j++){
				if(q.empty()) break;
				while(!q.empty() && x[j] - x[q.front()] > d){
					int k = q.front();
					s[f[k]] -= g[k];
					q.pop_front();
				}
				if(q.empty()) break;
				int k = q.front();
				f[j] = f[k] + 1;
				g[j] = s[f[k]];
				if(g[j] > 2) g[j] = 3;
				else if(g[j] == 2) ans++;
				
				//cout << "fg: " << i << ' ' << j << ' ' << k << ' ' << f[j] << ' ' << g[j] << '\n';
				
				while(!q.empty() && f[q.back()] > f[j]){
					int k = q.back();
					s[f[k]] -= g[k];
					q.pop_back();
				}
				q.push_back(j);
				s[f[j]] += g[j];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
