#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, lst[300005], t[300005], a[500005], len;
bool f[300005], p[300005];
vector<int> v;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++) {
		v.clear(); 
		len = 0;
		for(int j = 1;j <= m;j++) {
			f[j] = 0;
			lst[j] = 0;
			p[j] = 0;
		}
		for(int j = i;j <= n;j++) {
			if(f[a[j]]) {
				len++;
				for(int k = lst[a[j]] - len;k < v.size();k++) {
					f[v[k]] = 0;
					v[k] = 0; 
				}
				v.push_back(a[j]);
				lst[a[j]] = j;
				f[a[j]] = 1;
			} else {
				lst[a[j]] = j;
				f[a[j]] = 1;
				v.push_back(a[j]);
			}
		}
		for(auto cur : v) {
			if(p[cur] == 0) {
				t[cur]++;
				p[cur] = 1;
			}
		}
	}
	for(int i = 1;i <= m;i++) {
		cout << t[i] << ' ';
	}
	return 0;
}
 
