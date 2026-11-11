#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=500005;
int c,n,m,d,q,ans;
int w[MAXN],k[MAXN],t,a;
struct P{
	int u,w;
};
vector<P> e[50];
void dfs(int x,int y){
	if(x==y)
		return;
	for(int v=0;v<e[x].size();v++){
		ans+=e[x][v].w;
		dfs(v,e[x][v].u);
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>t>>a;
			e[a].push_back({j,t});
		}
	}
	while(q--){
		int x,y;
		ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		dfs(x,y);
		cout<<ans<<"\n";
	}
	return 0;
} 
