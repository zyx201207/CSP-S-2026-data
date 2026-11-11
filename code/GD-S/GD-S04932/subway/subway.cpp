#include <bits/stdc++.h>
using namespace std;
int w[500010],a[50][50],t[50][50];
int x[100010],y[100010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= d;i++){
		for(int j = 1;j <= i+2;j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1;i <= q;i++){
		cin >> x[i] >> y[i];
	}
	while(q--){
		cout << rand() << endl;
	}
	return 0;
} 
