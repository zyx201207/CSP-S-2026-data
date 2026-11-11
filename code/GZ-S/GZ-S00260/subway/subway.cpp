//甘森億 GZ-S00260 贵阳市云岩区中天中学 
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 +10;
int c, n, m, d, q;
int a[505], k[255], C[505][505], t[505][505], x, y;

int main(){
	freopen("subway.in", "r", stdin);
	freopen("aubway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i] ; j++){
			cin >> C[i][j] >> t[i][j];
			
		}
	}
	while(q--){
		cin >> x >> y;
		int l, o, r, u;
		int cnt;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= k[i] ; j++){
				if(x == C[i][j]){
					r = i, u = j;
				}
			}
	    }
	    for(int i = 1; i <= n; i++){
			for(int j = 1; j <= k[i] ; j++){
				if(	y == C[i][j]){
					l = i, o = j;
				}
			}
	    }
	    for(int i = 1; i <= n; i++){
	    	if(r == l){
	    		cnt = a[x] + a[y];
	    		for(int j = u; j <= o; j++){
	    			cnt += t[i][j];
				}
			}
		}
		cout << cnt;
	}
	return 0;
}
