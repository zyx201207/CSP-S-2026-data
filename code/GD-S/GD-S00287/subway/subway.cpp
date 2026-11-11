#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N],k[N];
struct node{
	int w,t;
};
vector<node>ve[N];
int dfs(int x,int y,int v){
	if(x==y) return v;
	for(int i=0;i<ve[x].size();i++){
		int e=ve[x][i].w;
		dfs(e,y,v+ve[x][i].t);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			int x,y;
			cin>>x>>y;
			ve[i].push_back({x,y});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=dfs(x,y,0);
		cout<<w[x]+w[y]+ans;
	}
	return 0;
}
