#include <bits/stdc++.h>
using namespace std;

long long a[200005];
int n, m;
long long d[13000][10000][2];

int main(){
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		for (int j = 1; j <= m; j++){
			d[i][j][1] = a[i];
		} 
	}
	for (int i = 1; i <= n; i++){
		d[i][0][1] = 1;
		d[i][0][0] = 1;
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j<= m; j++){
			d[i][j][0] = max(d[i-1][j-1][0], d[i-1][j-1][1]);	
		}
		for (int j = 1; j<= m; j++){
			d[i][j][1] = max(d[i][j][1] & d[i-1][j-1][0], d[i][j][1] & d[i-1][j-1][1]);
		} 
	}
	
	cout << max(d[n][m][1], d[n][m][0]);
	
	return 0;
}
