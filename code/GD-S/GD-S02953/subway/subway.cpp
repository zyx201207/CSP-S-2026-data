#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int,int>
const int N=1e6+100,mod=998244353;
int c,n,m,d,q;

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+1);
	vector<vector<int>> dis(n+m+1,vector<int>(n+m+1,1e18));
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			dis[a][m+i]=dis[m+i][a]=t;
		}
	}
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<'\n';
	}
	return 0;
}

