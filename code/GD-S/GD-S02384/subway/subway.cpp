#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int c,n,m,d,q;
int w[N];
bool f[N][N];
struct st{
	int to;
	int vl;
};
vector<st> a[N];
bool hs[N][N];
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
int ans=1e9;
void dfs(int ed,int u,int s){
	if(u==ed){
		ans=min(ans,s);
		return;
	}
	for(int i=1;i<=n;i++){
		if(hs[i][u]){
			for(auto j:a[i]){
				if(!f[u][j.to]){
					f[u][j.to]=1;
					f[j.to][u]=1;
					dfs(ed,j.to,s+j.vl);
					f[u][j.to]=0;
					f[j.to][u]=0;
				}
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int to,vl;
			cin>>to>>vl;
			a[i].push_back({to,vl});
			hs[i][to]=1;
		} 
	}
	while(q--){
		int sr,ed;
		cin>>sr>>ed;
		for(int i=1;i<=n;i++){
			if(hs[i][sr]) dfs(ed,sr,a[i][sr].vl);
		}
		cout<<w[sr]+ans+w[ed]<<'\n';
	}
	return 0;
}
