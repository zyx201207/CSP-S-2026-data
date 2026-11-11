#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1E5+10, N2=3E5+10, K=2;
int n,k;
int res1,res2;
vector<vector<int>>e(N);
vector<int>d1(N),d2(N);
void dfs1(int u,int v){
	for(auto&i:e[v]){
		if(i!=u){
			d1[i]=d1[v]+1;
			dfs1(v,i);
		}
	}res1=max(res1,d1[v]);
}void dfs2(int u,int v){
	for(auto&i:e[v]){
		if(i!=u){
			d2[i]=d2[v]+1;
			dfs2(v,i);
		}
	}res2=max(res2,d1[v]);
}int main(){
	ios::sync_with_stdio(0);
	ifstream fin("hub4.in");
	ofstream fout("hub.out");
	int c,t;
	fin>>c>>t;
	while(t--){
		res1=res2=0;
		fin>>n>>k;
		e.clear();
		d1.clear();
		d2.clear();
		e.resize(n+1);
		for(int i=0;i<n;i++){
			int u,v;
			fin>>u>>v;
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}d1[1]=d2[1]=0;
		dfs1(0,1);
		dfs2(0,1);
		cout<<min(res1,res2)<<endl;
	}return 0;
}

