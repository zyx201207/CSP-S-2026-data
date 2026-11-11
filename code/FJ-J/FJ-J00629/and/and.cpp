#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200010];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int now,int cnt,int j){
	if(now<ans){
		return;
	}
	if(cnt==m){
		ans=max(ans,now);
		return;
	}
	for(int i=j+1;i<=n;i++){
		dfs(now&a[i],cnt+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		dfs(a[i],1,i);
	}
	cout<<ans;
	return 0;
}
