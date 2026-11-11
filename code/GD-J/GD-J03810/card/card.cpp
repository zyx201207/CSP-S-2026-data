#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int &i : a) {
		cin >> i;
	}
	
	vector<int> ans(m + 1);
	for (int i = 0; i < n; i++) {
		vector<bool> inv(n);
		for (int j = i; j < n; j++) {
			for (int k = j - 1; k >= i; k--) {
				if (inv[k]) continue;
				if (a[k] == a[j]) {
					for (int l = k; l < j; l++) {
						inv[l] = true;
					}
					break;
				}
			}
		}
		
		vector<bool> added(m + 1);
		for (int j = i; j < n; j++) {
			if (!inv[j] && !added[a[j]]) {
				added[a[j]] = true;
				ans[a[j]]++;
			}
		}
	}
	
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}
