#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx,a[200005];
void dfs(long long now,long long cnt,long long ans){
	if(cnt==m){
		maxx=max(maxx,ans);
		return ;
	}
	if(now>n) return ;
	dfs(now+1,cnt+1,ans&a[now]);
	dfs(now+1,cnt,ans);
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i+1,1,a[i]);
	}
	cout<<maxx;
	return 0;
}
