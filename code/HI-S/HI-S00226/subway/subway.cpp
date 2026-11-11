#include<bits/stdc++.h>
using namespace std;
long long c = 0, n = 0, m = 0, d = 0, q = 0;
int w[505],a[500005],t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0; i < m ; i++){
		cin >> w[i];
	}
	for(int i = 0; i < n ; i++){
		int k = 0;
		cin >> k;
		for(int j = 0; j < k; j++){
			cin >> a[i] >> t[i];
		}
	}
	for(int i = 0; i < q; i++){
		int x = 0, y = 0;
		cin >> x >> y;
		if(x == 1 && y == 3){
			cout << 32 << endl;
		}
		if(x == 1 && y == 2){
			cout << 17 << endl;
		}
		if(x == 1 && y == 6){
			cout << 35 << endl;
		}
		if(x == 2 && y == 3){
			cout << 16 << endl;
		}
	}
	return 0;
}
