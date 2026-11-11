#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,s;
void dfs(long long k,long long ok,long long ans){
	if(ok>m){
		s=max(ans,s);
		return ;
	}
	if(k>n)return ;
	dfs(k+1,ok+1,ans & a[k]);
	dfs(k+1,ok,ans);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)dfs(i,1,a[i]);
	cout<<s;
	return 0;
}
