#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],cnt;
void dfs(long long i,long long ans,long long an){
	if(i<=n&&an==m) cnt=max(cnt,ans);
	else if(i>n||an>m) return;
	if(ans==0) dfs(i+1,a[i+1],an+1);
	else dfs(i+1,ans&a[i+1],an+1);
	dfs(i+1,ans,an);
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}
