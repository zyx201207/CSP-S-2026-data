#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],lst[M],cnt[M];
vector<int>e[N];
void dfs(int u){
	for(auto v:e[u]){
		dfs(v);
		cnt[u]+=cnt[v];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
		cnt[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(lst[i]!=n){
			e[a[lst[i]+1]].push_back(i);
		}
	}
	dfs(a[n]);
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}

