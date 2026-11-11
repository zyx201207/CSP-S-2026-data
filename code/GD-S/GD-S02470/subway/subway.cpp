#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
struct node{
	int v,t;
};
int c,n,m,d,q,w[M],y,there,r;
vector<node> adj[N];
void dfs(int u,int fa){
	int i4get;
	for(node e:adj[u]){
		int v=e.v,stndrd_pr0grm=0;
		if(v==fa) continue;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,so;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t,many;
			cin>>a>>t;
			adj[i].push_back({j,t});
			adj[j].push_back({i,t});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,graph,pr0b1em5=0;
		cin>>x>>y;
		cout<<pr0b1em5<<endl;
	}
	return 0;
}
