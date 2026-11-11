#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node {
	int a;
	char c;
};
int n, ans, cnt;
map<char, int> t;
node w[200005];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> w[i].a >> w[i].c;
		if(t[w[i].c] == 0) cnt++;
		t[w[i].c]++;
	}
	if(cnt == 1) {
		cout << 0;
		return 0;
	}
	
	int l = 1, r = n;
	int la = w[l].a, ra = w[r].a;
	char lc = w[l].c, rc = w[r].c;
	while(cnt > 1 && l < r) {
		
		if(lc != rc) {
			ans += min(la, ra);
		}
		int x = min(la, ra);
		la -= x;
		ra -= x;
		
		if(la == 0) {
			l++;
			t[lc]--;
			if(t[lc] == 0) cnt--;
			la = w[l].a, lc = w[l].c;
		}
		if(ra == 0) {
			r--;
			t[rc]--;
			if(t[rc] == 0) cnt--;
			ra = w[r].a, rc = w[r].c;
		}
	}
	cout << ans;
	return 0;
} 
