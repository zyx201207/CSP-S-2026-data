#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[1005],k[505],a[505][1005],t[505][1005];
int f[1005][1005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j)f[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++)cin >> a[i][j] >> t[i][j];
		for(int j=1;j<=k[i];j++){
			for(int o=1;o<=k[i];o++){
				if(j==o)continue;
				f[a[i][j]][a[i][o]]=min(f[a[i][j]][a[i][o]],t[i][j]+t[i][o]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(int o=1;o<=k[i];o++){
				for(int p=1;p<=k[j];p++){
					if(a[i][o]==a[j][p]){
						f[a[i][o-1]][a[j][p+1]]=t[i][o-1]+t[i][o]+t[j][p]+t[j][p+1];
					}
				}
			}
		}
	}
	for(int o=1;o<=m;o++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][o]+f[o][j]);
			}
		}
	}
	while(q--){
		int x,y;cin >> x >> y;
		cout << f[x][y]+w[x]+w[y] << "\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

21 10
*/
