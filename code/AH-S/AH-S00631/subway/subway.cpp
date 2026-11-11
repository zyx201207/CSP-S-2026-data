#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int c,n,m,d,q,w[N],t[N][N],best,vis[N],x,y;
struct Node{
	int ed,li;
};
vector<Node> g[N];
void dfs(int now,int ti){
	if(now==y){
		best=min(best,ti);
		return;
	}
	if(ti>=best){
		return;
	}
	for(int i=0;i<g[now].size();i++){
		int to=g[now][i].ed,l=g[now][i].li;
		if(!vis[to]){
			vis[to]=1;
			dfs(to,ti+t[now][l]+t[to][l]);
			vis[to]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int fi;
		cin>>x>>fi>>t[fi][i];
		for(int j=2;j<=x;j++){
			int k;
			cin>>k>>t[k][i];
			g[fi].push_back({k,i});
			g[k].push_back({fi,i});
		}
	}
	for(int i=1;i<=q;i++){
		memset(vis,0,sizeof vis);
		best=0x3f3f3f3f;
		cin>>x>>y;
		vis[x]=1;
		dfs(x,w[x]+w[y]);
		cout<<best<<"\n";
	}
	return 0;
}
