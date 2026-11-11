#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N = 5e5+5;
int a[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= m; ++i) {
		int cnt = 0;
		for (int j = 1; j <= n; ++j) {
			vector<int> v;
			set<int> s;
			
//			cout << "v======\n";

			for (int k = j; k <= n; ++k) {
				if (s.count(a[k])) while (v.back() != a[k]) s.erase(v.back()),v.pop_back();
				else v.push_back(a[k]),s.insert(a[k]);

//				for (int l : v) cout << l << " ";
//				cout << endl;

			}
			
//			cout << "^======\nlast:";
//			for (int l:v) cout << l << " ";
//			cout << endl;

			cnt += s.count(i);
		}
		cout << cnt << " ";
	}
	cout << endl;
	return 0;
}
