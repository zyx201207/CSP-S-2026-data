#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m;
int arr[N], cnt[M]; 
int sc[N];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> arr[n - i + 1];
	}
	vector<int> v;
	rep(i, 1, n) {
		if(sc[arr[i]] == 1) {
			rep(j, 0, v.size() - 1) {
				if(v[j] == arr[i]) {
					rep(k, j, v.size() - 1) sc[v[k]]--;
					v.erase(v.begin() + j, v.end());
				}
			} 
		}
		sc[arr[i]] += 1; 
		v.push_back(arr[i]);
		rep(j, 1, m) cnt[j] += sc[j];
	}
	rep(i, 1, m) cout << cnt[i] << ' ';
	return 0;
}

