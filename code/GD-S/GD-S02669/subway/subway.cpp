#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node{
	int a;
	int t;
};
int c,n,m,d,q;
int w[N];
vector<node> G[N];
vector<int>g[N];
long long ans=1e18;

void dfs(int now,int lst,int sum,int V){
	for(auto v:G[now]){	
		if(lst==v.a){
			
		}else{
			
		}
	}
}
void S(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		int x_;
		cin>>x_;
		for(int j=1;j<=x_;j++){
			int x,y;
			cin>>x>>y;
			G[x].push_back({i,y});
			//t[x].push_back(y); 
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ans=1e18;
		dfs(u,-1,w[u],v);
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--)S();
	return 0;
}

