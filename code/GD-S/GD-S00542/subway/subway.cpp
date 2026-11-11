#include <bits/stdc++.h>

using namespace std;

int w[100];
int t[100][100];
vector<int> edge[100];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
  int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
  for (int i = 1; i <= m; i++) {
  	cin >> w[i];
	}
	
	int tot = 0;
	for (int i = 1; i <= n; i++) {
	
		int k;cin >> k;
		for (int j = 1; j <= k; j++) {
			int y, z;
			cin >> y >> z;
			t[i][y] = z;
		}
  }
	 
	while (q--) {
		int x, y;
		cin >> x >> y;
		int sum = 0;
		
	} 
}
