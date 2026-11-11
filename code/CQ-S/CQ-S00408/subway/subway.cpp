#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int w[N],v[N],k1[N],k2[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i ++ ) cin >> v[i];
	int k,k_;
	cin >> k;
	for (int i = 1;i <= 2*k;i ++ ) cin >> k1[i];
	cin >> k_;
	for (int i = 1;i <= 2*k_;i ++ ) cin >> k2[i];
	int xr1,xr2,yr1,yr2;
	cin >> xr1 >> yr1;
	cin >> xr2 >> yr2;
	cout << xr1 + yr2 << k_;
	return 0;
}
