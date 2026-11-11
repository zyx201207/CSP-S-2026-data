#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
struct node {
	int num;
	char ch;
} sz[N], re[N];
string s, ss;
int n;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> sz[i].num >> sz[i].ch;
		for(int j=1; j<=sz[i].num; j++) {
			s += sz[j].ch;
		}
	}
	for(int i=n; i>=1; i--) {
		for(int j=1; j<=sz[i].num; j++) {
			ss += sz[i].ch;
		}
	}
	int ans = 0;
	for(int i=0;i<=ss.size() / 2;i++) {
		if(s[i] != ss[i]) ans++;
	}
	cout << ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
