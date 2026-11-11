#include <bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int n,m,ans;
int a[M],v[M];
bool vis[M];
inline void dfs(int id){
	if(id==m+1){
		int t=v[1];
		for(int i=2;i<id;i++){
			t=t&a[v[i]];
		}
		ans=max(ans,t);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			v[id]=i;
			dfs(id+1);
			vis[i]=false;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}