#include <bits/stdc++.h>
using namespace std;
const int N=2e4+10;
struct sta{
	int line,t;
	sta(int a,int b){
		line=a,t=b;
	}
};
vector<sta> lines[N];
bool vis[N];
struct edge{
	int v,line;
	edge(int a,int b){
		v=a,line=b;
	}
}; 
vector<edge> g[N];
long long ans=LLONG_MAX,l,r;
void dfs(int u,int fa,int line,int times){
	vis[u]=1;
	//cout << "u= "<<u << " times="<<times<<"\n";
	if(u==r) {
		for(auto k:lines[u]){
			if(k.line==line){
				times+=k.t,ans=min(ans,times*1LL);
				return ;
			}
		}
	}
	for(auto k: g[u]){
		int v=k.v,l=k.line,tmp=times;
		if(v==fa) continue ;
		if(line!=l) {
			bool flag1=0,flag2=0;
			for(auto kk: lines[u]){
				//cout << l<<" "<<kk.line<<" "<<u<<"\n";
				if(kk.line==l) tmp+=kk.t,flag1=1;
				else if(kk.line==line) tmp+=kk.t,flag2=1;
				if((line==-1&&flag1)||(flag1&&flag2)) break;
			}
		}
		if(!vis[v]) dfs(v,u,l,tmp);
		vis[v]=0;
	}
	
}
int c,n,m,d,q,up[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int k,u,t,lst=0;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> up[i];
	for(int i=1;i<=n;i++){
		lst=0;
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> u >> t;
			lines[u].push_back(sta(i,t));
			if(lst!=0) g[lst].push_back(edge(u,i)),g[u].push_back(edge(lst,i));
			lst=u;
		}
	}
	while(q--){
		memset(vis,0,sizeof vis);
		ans=LLONG_MAX;
		cin >> l >> r;
		dfs(l,0,0,0);
		int gg=ans+up[l]+up[r];
		cout << gg<<"\n";
	}
	return 0;
}
