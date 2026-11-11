#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int w[m];
	for(int i = 0;i < m+1;i++){
		cin >> w[i];
		cout << 1;
	}
	int a[n][500005],b[500005],cnt = 0;
	for(int i = 0;i < n;i++){
		int k;
		cin >> k;
		a[i][0] = k;
		cout << 1;
		for(int j = 1;j <= k*2;j++){
			cin >> a[i][j] >> b[cnt];
			cnt++;
			cout << a[i][j] << 1;
		}
	}
	return 0;
}
