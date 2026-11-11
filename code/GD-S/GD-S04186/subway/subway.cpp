#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int c,n,m,d,q,w[N];
vector<int> a[N],t[N];
long long dfs(int u,int v,long long q){
	if(u == v) return q;
	long long minn=455782;
	for(int i=1;i<=n;i++){
		for(auto w:a[i]){
			if(u !=0)
			if(a[i] != w){
				minn=min(dfs(w,v,q+t[u][w]));
			}
		}
	}
	return minn;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
			cin>>w[i]; 
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;		
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x == y){
			cout<<0;
			continue;
		}else{
			cout<<dfs(x,y); 
		}
	}
}
