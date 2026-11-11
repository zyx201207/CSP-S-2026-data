#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e4+10;

int w[M],a[N][M],t[M][N];
vector<int>G[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		cin>>a[i][1]>>t[a[i][1]][i];
		for(int j=2;j<=k;j++){
			cin>>a[i][j]>>t[a[i][j]][i];
			int u=(a[i][j-1]+n*(i-1)),v=(a[i][j]+n*(i-1));
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	for()
	while(q--){
		int x,y;
		cin>>x>>y;
	}
	
	return 0;
}

