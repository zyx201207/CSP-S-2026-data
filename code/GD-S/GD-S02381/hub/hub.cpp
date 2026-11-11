#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int c,T;
int n,k,fa[N],t[N];
vector<int> G[N];
int a[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool check(){
	int cnt=0;
	for(int i=1;i<=n;++i) t[i]=0;
	for(int i=1;i<=k;++i) t[a[i]]=1;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=k;++i){
		int u=a[i];
		for(auto v:G[u]){
			if(t[v]&&find(u)!=find(v)){
				fa[find(u)]=find(v);
			}
		}
	}
	for(int i=1;i<=n;++i) t[i]=0;
	for(int i=1;i<=k;++i){
		if(!t[find(a[i])]){
			cnt++;
			t[find(a[i])]++;
		}
	}
	if(cnt<=2) return true;
	else return false;
}
void dfs(int u){
	if(u==k+1){
		if(check()){
			for(int i=1;i<=k;++i){
				cout<<a[i]<<' ';
			}cout<<'\n';
		} 
		return;
	}
	for(int i=a[u-1]+1;i<=n;++i){
		a[u]=i;
		dfs(u+1);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n-1;++i){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1);
	}
	return 0;
}
