#include <bits/stdc++.h>

using namespace std;

const int N=500010;
int c, n, m, d, q;
int w[N], k[N];
int t[505][N];
int a[N];
int x[N], y[N];

struct tree
{
	int l[25];
}H[N];

int len[25];

int main ()
{
	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i=1; i<=m; i++){
		cin >> w[i];
	}
	for (int i=1; i<=n; i++){
		cin >> k[i];
		for (int j=1; j<=k[i]; j++){
			cin >> a[j] >> t[i][j];
		}
		for (int j=1; j<=k[i]; j++){
			H[ a[j] ].l[ ++len[ a[j] ] ] = a[j+1];
			H[ a[j-1] ].l[ ++len[a[j-1]] ] = a[j];
		}
	}
	for (int r=1; r<=q; r++){
		cin >> x[r] >> y[r];
	}

	for (int i=1; i<=m; i++){		////
		for (int j=1; j<=len[i]; j++){
			cout << H[i].l[j] << ' ';
		}cout << endl;
	}				////
	
	
	return 0;
}
