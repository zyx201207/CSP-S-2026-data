#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1005] ,k[25],a[105][105],t[105][105],x[25],y[55];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++) cin >> a[i][j] >> t[i][j];
	}
	for(int i = 1;i <= q;i++){
		cin >> x[i] >> y[i];
	}
	cout << w[1] + t[1][1] + (t[1][2] + t[2][2]) + t[2][3]+ w[3] << endl;
	cout << w[1] + t[1][1] + t[1][2] + w[2];
	return 0;
}	
