#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int c,n,m,d,q;
int w[N],a[N][N],t[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= n;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		long long ans = w[x] + w[y];
		cout << ans + t[1][x] + t[1][y] << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
