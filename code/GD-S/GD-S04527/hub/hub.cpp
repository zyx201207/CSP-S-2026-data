#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
vector <int> e[N];
int n,k,fa[N],de[N];
//int f[N][19];/
//vector <node> edge;
//int find(int x){
//	if(fa[x]==x) return fa[x];
//	fa[x]=find(fa[x]);
//	return fa[x];
//}
//void dfs(int u,int ff){
//	f[u][0]=ff,
//	for(auto &v:e[u]){
//		if(v==f) continue;
//		dfs(v,u);
//	}
//}
int main(){
	cin>>n>>k;
	if(k==n){
		cout<<"0";
		return 0;
	}
//	for(int i=1;i<n;i++){
//		int u,v;
//		cin>>u>>v;
//		edge.push_back({u,v});
//		e[u].push_back(v);
//		e[v].push_back(u);
//	}
//	dfs()
//	for(int msk=1;msk<(1<<n);msk++){
//		int cnt=0;
//		for(int i=1;i<=n;i++){
//			fa[i]=i;
//			if(msk>>(i-1)&1){
//				cnt++;
//				chs[i]=1;
//			}
//			else chs[i]=0;
//		}
//		if(cnt!=k) continue;
//		for(auto &ee:edge){
//			if(chs[ee.u]&&chs[ee.v]){
//				merge(ee.u,ee.v);
//			}
//		}
//	}
	return 0;
}
