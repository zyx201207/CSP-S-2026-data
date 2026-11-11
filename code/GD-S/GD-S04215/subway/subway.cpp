#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k,a[1005][1005],t[1005][1005],sum;
vector<int> b[1005];
int dfs(int u){
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,v;
			cin>>u>>t[i][j];
			sum+=t[i][j];
			if(j>=2){
				b[u].push_back(v);
			}
			v=u;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<sum;
	}
	return 0;
}
