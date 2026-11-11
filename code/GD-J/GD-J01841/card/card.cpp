#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N];
int cnt[N];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	if(n <= 500) {
		for(int i = 1;i <= n;i++) {
			vector<int> v;
			v.clear();
			for(int j = i; j <= n; j++) {
				int pos = -1;
				for(int k = 0; k < v.size(); k++) {
					if(v[k] == a[j]) {
						pos = k;
						break;
					}
				}
				if(pos != -1) {
					for(int k = 0; k <= v.size() - pos + 1;k++) {
						v.pop_back();
					}
				}
				v.push_back(a[j]);
			}
			for(int j = 0; j < v.size(); j++) {
				cnt[v[j]]++;
	//			cout << " i : " << i << "val : " << v[j] << '\n';
			}
		}
		for(int i = 1;i <= m;i++) {
			cout << cnt[i] << ' ';
		}
		return 0;
	} 
	else {
		for(int i = 1;i <= m;i++) {
			cout << n << ' ';
		}
	}
	return 0;
}
