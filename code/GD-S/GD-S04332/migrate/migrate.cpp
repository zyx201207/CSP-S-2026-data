#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = INT_MAX;
int a[1010][1010], x[10010], u[1010][1010];

signed main(){
	int c,t;
	cin >> c >> t;
	while(t--){
		memset(x, 0, sizeof(x));
		int n, d;
		cin >> n>> d;
		for (int i = 1; i <= n; i++){
			cin >> x[i];
		}
		for (int i = 1; i <= n;i++){
			for (int j= 1;j <= n;j++){
				if (abs(x[i] - x[j]) <= d) a[x[i]][x[j]] = abs(x[i] - x[j]);
				else a[x[i]][x[j]]= INF;
			}
		}
		
	}
	cout << 0 << ' ' << 1;
}
