#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],maxx;
void dfs(long long step,long long s,long long cnt){
	if(cnt==m){
		maxx=max(maxx,s);
		return ;
	}
	if(step==n+1||cnt+(n-step+1)<m)return ;
	if(cnt==0)dfs(step+1,a[step],cnt+1);
	else dfs(step+1,s&a[step],cnt+1);
	dfs(step+1,s,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1ll,0ll,0ll);
	cout<<maxx;
	return 0;
}
