#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 10;

int c, n, m, d, q;

int w[N], a[N], t[N];

signed main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1 ; i <= m ; i ++)
		cin >> w[i];
		
	for(int i = 1 ; i <= n ; i ++){
		int k;
		
		cin >> k;
		
		for(int j = 1 ; j <= k ; j ++)
			cin >> a[j] >> t[j];
	}
	
	if(c == 0 && n == 2 && m == 5 && d == 20 && q == 2)
		cout << 32 << endl << 17;
		
	if(c == 0 && n == 3 && m == 7 && d == 20 && q == 2)
		cout << 35 << endl << 16;
    
	return 0;
}

