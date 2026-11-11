#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],cnt[1000010],ans[1000010],fa[1000010];
set<int>s[1000010];
vector<int>V[1000010];
void dfs(int k){
	ans[k]=cnt[k];
	for(auto p:V[k]){
		dfs(p);
		ans[k]+=ans[p];
	}
//	cout<<ans[k]<<'\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=n;i>=1;i--){
		if(i==n){
			fa[a[i]]=a[i];
		}
		if(fa[a[i]]==0){
			V[a[i+1]].push_back(a[i]);
			fa[a[i]]=a[i+1];
//			cout<<i<<" ";
		}
	}
	dfs(a[n]);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
