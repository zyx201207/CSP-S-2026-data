#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,w[500005],k[505],a[505][505],t[505][505],r1[500005],r2[500005];
	cin >> c >> n >> m >> d >> q;
	for(int i=0;i<m;i++){
		cin >> w[i];
	}
	for(int i=0;i<n;i++){
		cin >> k[i];
		for(int j=0;j<k[i];i++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin >> r1[i] >> r2[i];
		cout << w[r1[i]] + w[r2[i]] + a[0][r1[i]] + a[0][r2[i]];
	}
	return 0;
}
