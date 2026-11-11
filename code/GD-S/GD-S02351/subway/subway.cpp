#include<bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 250;
int w[N], a[N], b[N];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	int k;
	long long h = 0;
	for(int l = 1; l <= n; l++){
		cin >> k;
		h += k;
		for(int j = h - k + 1; j <= h; j++){
			cin >> a[j] >> b[j];
		}
		a[h + 1] = 0;
		b[h + 1] = 0;
		h++;
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		long long qwe = 0;
		long long f = 0;
		qwe += w[x];
		qwe += w[y];
		for(int i = 1; i <= h; i++){
			if(a[i] == x){
				if(a[i - 1] == y){
					qwe += b[i];
					qwe += b[i - 1];
					cout << qwe;
					f = 1;
					break;
				}else if(a[i + 1] == y){
					qwe += b[i];
					qwe += b[i + 1];
					cout << qwe;
					f = 1;
					break;
				}else{
					continue;
				}
			}
		}
		if(f == 0){
			cout << qwe + 13;
		}
	}
	return 0;
}
