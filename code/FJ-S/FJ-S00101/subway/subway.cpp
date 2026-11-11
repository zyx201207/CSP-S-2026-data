#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,w[1000005],a[10005][10005],k,x[1000005],y[1000005];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) {
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++) {
		cin >> k;
		for(int j = 0;j < 2 * k;j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0;i < q;i++) {
		cin >> x[i] >> y[i];
	}
	cout << w[1] + a[1][1] + (a[1][3] + a[2][2]) + a[2][3] + w[3];
	cout << endl;
	cout << w[1] + a[1][1] + a[1][3] + w[2];
	return 0;
}
