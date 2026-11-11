#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline void pop(vector<vector<int>> &p) {
	bool yes;
	for(int x = 0;x < p.size() - 1;x++) {
		yes = true;
		for(int i = 0;i < p.size() - 1;i++) {
			if(p[i].size() < p[i + 1].size()) {
				swap(p[i], p[i + 1]);
				yes = false;
			}
			else if(p[i].size() == p[i + 1].size())
			for(int j = p[i].size() - 1;j >= 0;j--) {
				if(p[i][j] < p[i + 1][j]) {
					yes = false;
					swap(p[i], p[i + 1]);
					break;
				}
			}
		}
		if(yes) break;
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	unsigned long long a[n];
	for(int i = 0;i < n;i++) cin >> a[i];

	vector<vector<int>> a2(n, vector<int>());
	for(int i = 0;i < n;i++) {
		while(a[i]) {
			a2[i].push_back(a[i] % 2);
			a[i] /= 2;
		}
	}
	pop(a2);

//	for(int i = 0;i < a2.size();i++) {
//		for(int j = 0;j < a2[i].size();j++) {
//			cout << a2[i][j] << ' ';
//		}
//		cout << endl;
//	}

	long t2;
	for(int i = 0;i < n;i++) {
		t2 = 1;
		for(int j = 0;j < a2[i].size();j++) {
			if(a2[i][j]) a[i] += t2;
			t2 *= 2;
		}
	}

	int ans = a[0];
	for(int i = 1;i < m;i++) {
		ans &= a[i];
	}
	cout << ans << '\n';
	return 0;
}

