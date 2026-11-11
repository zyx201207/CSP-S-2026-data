#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500010], a[520], t[520];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> t[i];
	}
	for(int i = 1; i <= q; i++){
		cout << w[i];
	}
	return 0;
} 
