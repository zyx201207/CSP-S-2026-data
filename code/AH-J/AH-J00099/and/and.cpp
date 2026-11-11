#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200010],ans;
void dfs(long long d,long long cnt,long long he){
	if(cnt==m){
		ans=max(ans,he);
		return;
	}
	if(d>n){
		return;
	}
	if(cnt>m){
		return;
	}
	if(cnt==0){
		dfs(d+1,cnt+1,a[d]);
		dfs(d+1,cnt,he);
	}else{
		dfs(d+1,cnt+1,he&a[d]);
		dfs(d+1,cnt,he);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
