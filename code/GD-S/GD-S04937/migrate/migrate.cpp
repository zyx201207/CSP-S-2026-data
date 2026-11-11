#include <bits/stdc++.h>

using namespace std;

int n, d;
int x[2010];
int g[2010][2010];

void mkgraph() {
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if((x[j] - x[i]) <= d) g[i][j] = x[j] - x[i];
			else {
				g[i][j] = 100000000000000; 
			} 
			cout << "图上" << i << "到" << j << "的边长为" << g[i][j] << endl; 
		}
	}
	return ;
}

int djkstra() {
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j++) {
			
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	int sa = 0;
	while(t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
//		mkgraph();
		cout << sa;
		sa++;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
