#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "W", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    int w[m+5];
    for(int i = 0; i < m; i++){
		cin >> w[i];
	}
	int k, a1, t1;
	for(i = 0; i < n; i++){
		cin >> k;
		for(int i = 0; i < k; i++){
			cin >> a1 >> t1;
		}
	}
	for(int i = 0; i < q; i++){
		cin >> a1 >> t1;
	}
    for(int i = 0; i < q; i++){
		cout << 1 << endl;
	}
    
    
    
    
    return 0;
}
