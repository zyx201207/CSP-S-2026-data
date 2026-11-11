#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,p,w[505],a[150005][500005],x[100005],y[100005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> p;
	for (int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1;i <= q;i++){
		cin >> x[i] >> y[i];
	}
	return 0;
}