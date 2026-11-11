#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
struct S {
	ull len; char c;
};

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	cin >> n;
	vector<S> a;
	
	for (int i = 1; i <= n; i++) {
		ull l; char c;
		cin >> l >> c;

		a.push_back({l, c});
	}
	
	ull ans = 0;
	int l = 0, r = n - 1;
	ull sl = a[l].len, sr = a[r].len;
	while (l < r) {
		if (sl >= sr) {
			if (a[l].c != a[r].c) ans += sr;
			sl -= sr;
			--r, sr = a[r].len;
			if (sl == 0) ++l, sl = a[l].len;
		} 
		else {
			if (a[l].c != a[r].c) ans += sl;
			sr -= sl;
			++l, sl = a[l].len;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
