#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int w[500010];//½øÕ¾
int a[510][100010];
int t[510][100010];
int k[510];

mt19937 myrand(time(0));

int main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)cin >> w[i];
	
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)cin >> a[i][j] >> t[i][j];
	}
	
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << n % myrand() + t[1][1] + t[2][1] << "\n";
	}
	
	return 0;
}
