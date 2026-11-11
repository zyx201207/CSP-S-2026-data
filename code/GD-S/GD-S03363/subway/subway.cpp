#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	vector<ll> w(m+1);
	for(int i=1;i<=m;i++) cin >> w[i];
	vector<vector<ll>> dis(m+1,vector<ll>(m+1,1e18));
	for(int i=1;i<=m;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		vector<int> a(k+1);
		vector<ll> t(k+1);
		for(int j=1;j<=k;j++) cin >> a[j] >> t[j];
		for(int x=1;x<=k;x++){
			for(int y=x+1;y<=k;y++){
				dis[a[x]][a[y]]=dis[a[y]][a[x]]=min(dis[a[x]][a[y]],t[x]+t[y]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << w[x]+w[y]+dis[x][y] << '\n';
	}
	return 0;
}
