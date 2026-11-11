#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5e2 + 5;
const int MAXM = 2e2 + 5;

int n, m;
int a[MAXN];
int pos[MAXM];
int b[MAXN];
int cnt[MAXM];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i ++) {
		int k = 0;
		memset(pos, 0, sizeof pos);
		for (int j = i; j <= n; j ++) {
			if (pos[a[j]] == 0) {
			    ++ k;
				pos[a[j]] = k;
				b[k] = a[j];
			} else {
				int tmpk = k;
				k = pos[a[j]] - 1;
				for (int g = pos[a[j]]; g <= tmpk; g ++) {
					pos[b[g]] = 0;
					b[g] = 0;
				}
				++ k;
				pos[a[j]] = k;
				b[k] = a[j];
			}
		}
		for (int j = 1; j <= k; j ++) {
			cnt[b[j]] ++;
		}
	}
	
	for (int i = 1; i <= m; i ++) {
		cout << cnt[i] << ' ';
	}
	cout << '\n';
	
	return 0;
}
