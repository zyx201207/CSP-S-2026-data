#include<bits/stdc++.h>
using namespace std;
#define lli long long
namespace fastio{
	template <typename t>void read(t &n){
		t x=0,f=1;char c=' ';
		for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
		for(;isdigit(c);c=getchar()) x=x*10+c-'0';
		n=x*f;
	}
}using namespace fastio;
const int N=1e6+7;
int n,m,c,d,q;int w[N];int be,nd;int k[N];
vector<pair<int,int> > v[666];int ans=1e9+9;bool vis[N];
void dfs(int f,int c){
	vis[f]=1;
	if(f==nd){
		ans=min(ans,c);return;
	}
	for(int i=0;i<k[f];i++){
		if(!vis[v[f][i].first]){
			vis[v[f][i].first]=1;
			dfs(v[f][i].first,c+v[f][i].second);
			vis[v[f][i].first]=0;
		}
	}
}
int main(){
	freopen(cin,"r",subway.in);
	freopen(cout,"w",subway.out);
	read(c);read(n);read(m);read(d);read(q);
	for(int i=1;i<=m;i++){
		read(w[i]);
	}
	for(int i=1;i<=n;i++){
		int e;
		read(e);k[i]=e;
		for(int j=1;j<=e;j++){
			int a,t;read(a);read(t);
			
			v[i].push_back({a,t});
		}
	}
	for()
	while (q--){
		ans=1e9+9;
		memset(vis,0,sizeof(vis));
		read(be);read(nd);
		dfs(be,w[be]+w[nd]+v[be][0].second);
		printf("%d\n",ans);
	}
	return 0;
}

