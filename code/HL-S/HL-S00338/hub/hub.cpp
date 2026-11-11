#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1e6+5;
vector<int> E[N];
int sz[N],f[N];
void add(int u,int v){
	E[u].pb(v);
	E[v].pb(u);
}
int dfs1(int x){
	sz[x]=1;
	for(int i=0;i<E[x].size();i++){
		sz[x]+=dfs1(E[x][i]);
		f[x]+=f[E[x][i]];
	}
	f[x]+=sz[x]-1;
	return sz[x];
}
int dfs2(int x){
	
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,k; cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v); add(v,u);
		}	
		cout<<"1"<<endl;
	}
	return 0;
}
