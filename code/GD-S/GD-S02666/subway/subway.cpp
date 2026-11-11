#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500005],a[505],t[505];
vector<int> a[505];
vector<int> t[505];
int maxn;
void dfs(int i,int j,int id,int y,int sum){
	if(id==y){
		maxn=max(sum,maxn);
		return;
	}
	dfs(i,j+1,a[i][j+1],y,sum+t[i][j]);
	for(int k=1;k<=m;k++){
		if(a[i][j]==a[i+1][k]){
			dfs(i+1,j+k,a[i+1][j+k],y,sum+t[i][j]);
		}
	}
	
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(j=1;j<=n;j++) {
		int T;
		cin>>T;
		for(int i=1; i<=T; i++) {
			int x,y;
			cin>>x,y;
			a[j][i]_push.back(x);
			t[j][i]_push.back(y);
		}

	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		maxn=w[x]+w[y];
		dfs(x,x,x,y,maxn);
		cout<<maxn<<endl;
	}
	return 0;
}
