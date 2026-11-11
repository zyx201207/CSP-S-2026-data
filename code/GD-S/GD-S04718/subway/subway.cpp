#include <bits/stdc++.h>
using namespace std;
int w[500005],a[505][5005],t[505][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		long long sum = 0;
		sum += w[x] + w[y];
		cout << sum << endl;
	}
	return 0;
}
