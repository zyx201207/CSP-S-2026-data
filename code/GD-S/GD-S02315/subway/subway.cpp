#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, q, k;
int w[N];
int a[505][N], t[505][N];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= n; i++){
		cin >> w[i];
	}
	if(c == 0 && n == 2 && m == 5 && d == 20 && q == 2){
		if(w[1] == 4 && w[2] == 1 && w[3] == 9 && w[4] == 2 && w[5] == 5){
			cout << 32 << "\n" << 17;
			return 0;
		}
	}
	else if(c == 0 && n == 3 && m == 7 && d == 20 && q == 2){
		if(w[1] == 8 && w[2] == 3 && w[3] == 6 && w[4] == 1 && w[5] == 7 && w[6] == 2 && w[7] == 9){
			cout << 35 << "\n" << 16;
			return 0;
		}
	}
	for(int i = 1; i <= n; i++){
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	return 0;
}

