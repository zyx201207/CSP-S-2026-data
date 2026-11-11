#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,m,a[N],ma,tmp,cnt,ans;
vector<int> g[N][40];

void init(int id) {
	int x = a[id];
	for(int i = 0; i <= 30 && x; i ++) {
		if (x & 1) {
			g[cnt][i].push_back(id);
			tmp = max(tmp,i);
		}
		x >>= 1;
	}
	return ;
}

void push(int id) {
	int x = a[id];
	for(int i = 0; i <= ma && x; i ++) {
		if (x & 1) {
			g[cnt][i].push_back(id);
		}
		x >>= 1;
	}
	return ;
}


int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		init(i);
	}
	if (m == 0) {
		cout << 0;
		return 0;
	}
	ma = tmp + 1;
	while (ma) {
		ma --;
		if (g[cnt][ma].size() >= m) {
			cnt ++;
			for(auto i : g[cnt - 1][ma]) {
//				cout << a[i] << ' ';
				push(i);
//				cout << endl;
			}
			ans += pow(2,ma);
//			cout << ans << endl;
		}
	}
	cout << ans;
	return 0;
}
