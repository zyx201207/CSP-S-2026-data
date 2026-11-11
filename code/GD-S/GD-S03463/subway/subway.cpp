#include <iostream>
using namespace std;

int w[500005];

int k[500005]; 
int a[500005][500005], t[500005][500005];
int x[100005], y[100005];

int time = 2147483647;
void dfs(int n, int nown, int ti, int x1, int y1, int nows) {
	if(nows == y1) {
		time = min(time, ti);
		return;
	}
	for(int i=1;i<=n&&i!=nown;i++) {
		for(int j=1;j<=k[i];j++) {
			dfs(n, i, ti+t[i][j], x1, y1, a[i][j]);
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) {
		scanf("%d", &w[i]);
	}
	
	for(int i=1;i<=n;i++) {
		scanf("%d", &k[i]);
		for(int j=1;j<=k[i];j++) {
			scanf("%d %d", &a[i][j], &t[i][j]);
		}
	}
	for(int i=1;i<=n;i++) {
		scanf("%d %d", &x[i], y[i]);
		dfs(n, 0, w[x[i]]+w[y[i]], x[i], y[i], x[i]);
		cout << time << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

