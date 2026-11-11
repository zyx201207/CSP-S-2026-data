#include<bits/stdc++.h>
#define itn int
using namespace std;
const int N=5e5+10;
int st,se;
int w[N];
struct gg{
	int id,w;
}w2;
struct edge{
	int v,w;
};
int ans=INT_MAX,cnt=0;
vector<edge> g[N];
void dfs(int x){
	if(x==se){
		ans=min(ans,cnt);
		return;
	}
	for(auto ed:g[x]){
		
	}
}
signed main(){
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		for(int i=1;i<=num;i++){
			int a,b;
			cin>>a>>b;
			g[a].push_back(w2.id,b+w2.w);
			g[w2.id].push_back(a,b+w2.w);
			w2={a,b};
		}
	}
	while(q--){
		cin>>st>>se;
		dfs(st);
	}
	return 0;
}
