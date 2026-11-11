#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, p;
int w[200005],f[500][500],a[100],t[100];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> c >> n >> m >> d >> p;

	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1,k;i<=n;i++){
		cin >> k;

		for (int j = 1;j <=k;j++){
			cin >> a[j] >> t[j];

			f[a[j]][i*100+a[j]] = t[j];
			f[i*100+a[j]][a[j]] = t[j];
		}

		for (int j = 2;j <=k;j++){
			f[i*100+a[j-1]][i*100+a[j]] = 0;
			f[i*100+a[j]][i*100+a[j-1]] = 0;
		}

	}

	for (int cnt = 1;cnt <= 10;cnt++){
		for(int i=1;i<=n*100+m;i++){
			for(int j = i+1;j<=n*100+m;j++){
				for(int k = 1;k<=n*100+m;k++){
					f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
					f[j][i] = f[i][j];

				}
			}
		}
	}

	int x,y;
	for (int i=1;i<=p;i++){

		cin >> x >> y;
		cout << w[x]+w[y]+f[x][y] << endl;

	}

	return 0;
};
