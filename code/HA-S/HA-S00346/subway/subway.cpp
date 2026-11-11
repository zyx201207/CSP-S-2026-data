#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, a[501], sta[501][501], r, goal;

int pd(int x, int time){
	if (x = goal) return time;
	for (int i = 1; i <= n; i++)
		if (sta[i][x] != 0)
			for (int j = 1; j <= m; j++)
				pd(j, time + sta[i][j]);
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		int temp;
		cin >> temp;
		for (int j = 1; j <= temp; j++){
			int cnt;
			cin >> cnt;
			cin >> sta[i][cnt];
		}
	}
	for (int i = 1; i <= q; i++){
		cin >> r >> goal;
		cout << a[r] + pd(r, 0) + a[goal] << endl;
	}
	
	return 0;
}
