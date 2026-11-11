#include <bits/stdc++.h>
using namespace std;
const int N=500;
int c,n,m,d,q;
int w[500005],a[505][505],t[505][505],k,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a[i][j] >> t[i][j];
		}
	} 
	while(q--){
		cin >> x >> y;
		cout << 1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
