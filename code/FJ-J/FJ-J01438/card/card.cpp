#include<bits/stdc++.h>
using namespace std;
vector<int> g[303030];
int ans[303030];
void dfs(int x){
	ans[x]=1;
	for(auto v:g[x]){
		dfs(v);
		ans[x]+=ans[v];
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int> last(m+1);
	last[a[n]]=n;
	vector<int> idx(m+1);
	idx[a[n]]=n;
	for(int i=n-1;i>=1;i--){
		if(!last[a[i]]){
			g[i+1].push_back(i);
			last[a[i]]=i;
			idx[a[i]]=i;
		}else {
			g[last[a[i]]].push_back(i);
			last[a[i]]=i;
		}
	} 
	dfs(n);
//	for(int i=1;i<=n;i++)cout<<g[i].size()<<" ";
//	cout<<"\n";
	for(int i=1;i<=m;i++)cout<<ans[idx[i]]<<" ";
	cout<<"\n";
	return 0;
}

