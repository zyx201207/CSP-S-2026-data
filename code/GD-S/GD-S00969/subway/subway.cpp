#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int o,n,m,d,q,a[505][maxn],c[505][maxn],w[maxn];
map<pair<int,int>,int> dp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>o>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>c[i][j];
		}
		for(int v=1;v<=k;v++){
			for(int u=1;u<=k;u++){
				if(u==v) continue;
				dp[{a[i][u]+(i-1)*m,a[i][v]+(i-1)*m}]=c[i][v];
			}
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				dp[{a[i][j]+(i-1)*m,a[k][j]+(k-1)*m}]=dp[{a[k][j]+(k-1)*m,a[i][j]+(i-1)*m}]=c[i][j]+c[k][j];
			}
		}
	}
	for(int k=1;k<=n*m;k++){
		for(int i=1;i<=n*m;i++){
			for(int j=1;j<=n*m;j++){
				dp[{i,j}]=max(dp[{i,j}],dp[{i,k}]+dp[{k,j}]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		cout<<w[x]+dp[{x,y}]+w[y];
	}
	return 0;
}
