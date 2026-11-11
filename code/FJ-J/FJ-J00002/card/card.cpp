#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10,MAXM=3e5+10;
vector<int> e[MAXM];
int a[MAXN],lst[MAXM],ans[MAXM];
int n,m;
void addEdge(int u,int v){
	e[u].push_back(v);
	return;
}
void DFS(int u,int fa){
	for(int i=0;i<(int)(e[u].size());i++){
		int v=e[u][i];
		DFS(v,u);
		ans[u]+=ans[v];
	}
	return;
}
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
	}
	ans[a[n]]++;
	for(int i=n-1;i>=1;i--){
		if(i==lst[a[i]]){
			addEdge(a[lst[a[i+1]]],a[i]);
		}
		ans[a[i]]++;
	}
	DFS(a[n],0);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}