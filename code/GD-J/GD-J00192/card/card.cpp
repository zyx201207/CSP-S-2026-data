#include<bits/stdc++.h>
using namespace std;

int a[500010], ans[300010], tmp[500010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(ans, 0, sizeof(ans));
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for(int i=1; i<=n; i++) {
		memset(tmp, 0, sizeof(tmp));
		int cnt = 1;
		for(int j=i; j<=n; j++) {
			if(j == i) {
				tmp[1] = a[j];
				cnt++;
				continue;
			}
			int flag = false;
			for(int h=1; h<=n; h++) {
				if(tmp[h] == a[j]) {
					flag = true;
					cnt = h + 1;
					for(int l=h+1; l<=n; l++) {
						tmp[l] = 0;
					}
					break;
				}
			}
			if(!flag) {
				tmp[cnt++] = a[j];
			}
		}
		for(int i=1; i<=n; i++) {
			ans[tmp[i]]++;
		}
	}
	for(int i=1; i<=m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}

