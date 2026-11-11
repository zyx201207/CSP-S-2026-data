#include<iostream>
#include<vector>
using namespace std;
#define N 500005
#define M 300005
int a[N];
int p[M];
int vis[N];
int ca[N];
int n,m;
int ans[M];
vector<int> dfs(int x){
	if(x==n){
		if(!vis[x]) ans[a[x]]++;
		vis[x]=1;
		//sum[a[x]]=1;
		return {a[x]};
	}
	if(ca[x]==n+1){
		auto k=dfs(x+1);
		if(!vis[x+1]){
			for(auto s : k){
				ans[s]++;
			}
		}
		vis[x+1]=1;
		k.push_back(a[x]);
		return k;
	}
	auto k=dfs(ca[x]);
	if(!vis[ca[x]]){
		for(auto s : k){
			ans[s]++;
		}
	}
	vis[ca[x]]=1;
	return k;
} 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++) p[i]=n+1;
	for(int i=n;i>=1;i--){
		ca[i]=p[a[i]];
		if(ca[p[a[i]]]!=n+1 && p[a[i]]!=n+1) ca[i]=ca[p[a[i]]];
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			auto k=dfs(i);
			for(auto s : k){
				ans[s]++;
			}
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

