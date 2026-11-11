#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[200005];
bool s[200005];
void dfs(int t,long long x){
	if(t==m){
		ans=max(ans,x);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!s[i]){
			s[i]=1;
			if(t==0)dfs(t+1,a[i]);
			else dfs(t+1,x&a[i]);
			s[i]=0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0);
	cout<<ans;
	return 0;
}
