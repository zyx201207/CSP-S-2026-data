#include<bits/stdc++.h>
using namespace std;

bool num[200010][40];
int mxwei = -1;

vector<int> bj1, bj2;

void ten2two(int x, int id) {
	int cnt = 0;
	while(x) {
		int tmp = x % 2;
		num[id][cnt] = tmp;
		cnt++;
		x /= 2;
	}
	mxwei = max(mxwei, cnt);
	return ;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		ten2two(x, i);
	}
	for(int i=mxwei; i>=0; i--) {
		int cnt = 0;
		if(bj1.empty()) {
			for(int j=1; j<=n; j++) {
				if(num[j][i]) {
					cnt++;
					bj1.push_back(j);
				}
			}
			if(cnt < m) bj1.clear();
			else ans = 1;
			cnt = 0;
			continue;
		}
		for(int j=0; j<(int)bj1.size(); j++) {
			if(num[bj1[j]][i]) {
				cnt++;
				bj2.push_back(bj1[j]);
			}
		}
		if(cnt < m) {
			bj2.clear();
			ans *= 2;
		} else {
			bj1 = bj2;
			bj2.clear();
			ans = ans * 2 + 1;
		}
		cnt = 0;
	}
	cout << ans;
	return 0;
}

