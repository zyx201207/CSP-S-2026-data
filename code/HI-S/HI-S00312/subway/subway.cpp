#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 2e4+10,N=510;

int c,n,m,d,q;
int w[M];
int k[M][N];
vector<int> fa[M];
long long a[N][N];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	if(c >= 0 && c <= 15) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i != j) a[i][j] = 1e12;
			}
		}
		for(int i=1; i<=m; i++) {
			cin >> w[i];
		}
		for(int i=1; i<=n; i++) {
			int tmp;
			cin >> tmp;
			for(int j=1; j<=tmp; j++) {
				int p,q;
				cin >> p >> q;
				k[p][i] = q;
				fa[p].push_back(i);
			}
		}
		for(int i=1; i<=m; i++) {
			if(fa[i].size()>=2) {
				for(int j=0; j<fa[i].size(); j++) {
					for(int l=0; l<fa[i].size(); l++) {
						int k1 = fa[i][j],k2=fa[i][l];
						a[k1][k2] = min(a[k1][k2],(long long)k[i][k1]+k[i][k2]);
					}
				}
			}
		}
		for(int l=1;l<=n;l++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					a[i][j] = min(a[i][j],a[i][l]+a[l][j]);
				}
			}
		}
		while(q--){ 
			int x,y;
			long long ans = LLONG_MAX;
			cin >> x >> y;
			for(int i=0;i<fa[x].size();i++){
				for(int j=0;j<fa[y].size();j++){
					int k1 = fa[x][i],k2=fa[y][j];
					ans = min(ans,w[x]+w[y]+k[x][k1]+k[y][k2]+a[k1][k2]);
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}

