#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200020],ans;
void dfs(int len,int NextId,long long NextAns){
	if(len==m){
		ans=max(ans,NextAns);
		return;
	}
	for(int i=NextId+1;i<=n;i++){
		dfs(len+1,i,NextAns&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(1,i,a[i]);
	}
	cout<<ans;
	return 0;
}
