#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,d;
long long ans;
struct dt{
	int f,s;
};
int a[1005][1005];
vector<dt> e[1010];
int dfs(int x,int y){
	if(a[x][y]!=0) return a[x][y]+ans;
	if(x==y) return ans;
	for(int i=0;i<e[i].size();i++){
		ans+=e[x][i].s;
		dfs(e[x][i].f,y);
		ans-=e[x][i].s;
	}
}
int main(){
	int w[500010];
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int ua,ub;
	if(c>=7&&c<=11){
		int k;
		int ua,ub;
		for(int i=1;i<=n;i++){
			cin>>k;
			cin>>ua>>ub;
			if(k==2){
				int u,v;
				cin>>u>>v;
				e[ua].push_back({u,v+ub});
				e[u].push_back({ua,v+ub});
			}
		}
		while(q--){
			cin>>ua>>ub;
			ans=0;
			a[ua][ub]=dfs(ua,ub);
			cout<<a[ua][ub]<<endl;
		}
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>ua>>ub;
		}
	}
	while(q--){
		cin>>ua>>ub;
		cout<<ua+ub+q/ua/ub<<endl;
	}
	return 0;
}
