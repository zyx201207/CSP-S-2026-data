#include<bits/stdc++.h>
using namespace std;
const int N = 505,M = 5e5 + 50;
int c,n,m,d,q,w[M],a[N][M],t[N][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m; ++ i) cin >> w[i];
	for(int i = 1;i <= n; ++ i){
		int k;
		cin >> k;
		for(int j = 1;j <= k; ++ j){
			cin >> a[i][j] >> t[i][j];
		} 
	}
	for(int i = 1;i <= q;++ i){
		int x,y,ans = 0;
		cin >> x >> y;
		ans += w[x] + w[y];
		ans += a[1][1] + t[1][1];
		cout << ans << endl;
	}
	return 0;
}
//这无疑是构时的喵(QAQ) 
