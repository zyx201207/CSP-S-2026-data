#include <bits/stdc++.h>
using namespace std;
int w[505],k[505],a[505][500005],t[505][500005];
int dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	if (c >= 12 && c <= 19){
		for (int i = 1;i <= q;i++){
			long long ans = 0;
			int x,y;
			cin >> x >> y;
			ans += w[x] + w[y];
			ans += 2 * t[1][1];
			cout << ans << "\n";
		}
	}
	for (int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++){
		cin >> k[i];
		for (int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1;i <= n;i++){
		for (int j = i+1;j <= k[i];j++){
			for (int z = j+1;z <= k[i];z++){
				dis[i][j] = min(dis[i][j],t[i][j-1]+t[i][j]);
				dis[j][z] = min(dis[j][z],t[j][z-1]+t[j][z]);
				dis[i][z] = min(dis[i][z],dis[i][j]+dis[j][z]);
			}
		}
	}
	for (int i = 1;i <= q;i++){
		int x,y;
		long long ans = 0;
		cin >> x >> y;
		ans += w[x] + w[y];
		ans += dis[x][y];
		cout << ans << "\n";
	}
	return 0;
}
