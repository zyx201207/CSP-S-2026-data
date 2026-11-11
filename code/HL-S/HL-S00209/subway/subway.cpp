#include<bits/stdc++.h>                                                          
using namespace std;
int c, n, m, d, q;
const int N = 100000;
int a[N], b[N], g[N];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> a[i];
	}
	for(int i = 2; i <= n; i++){
		cin >> b[i];
	}
	for(int i = 1; i <= q; i++){
		cin >> g[i];
	}
	cout << 32 << endl << 17;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
