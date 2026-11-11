#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[200010],vis[200010],path[200010];
ll ans,maxn,flaga=1,flagb=1,flag4=1;
void dfs(ll w){
	if(w>m){
		ll cnt=path[1];
		for(int i=2;i<=m;i++)cnt=cnt&path[i];
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			path[w]=a[i];
			dfs(w+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)flagb=0;
		if(a[i]>=4)flag4=0;
		maxn=max(maxn,a[i]);
		ll tmp=a[i];
		while(tmp>1){
			if(tmp%2==0){
				tmp/=2;
			}
			else{
				flaga=0;
				break;
			}
		}
	}
	ll tmp=n;
	while(tmp>1){
		if(tmp%2==0){
			tmp/=2;
		}
		else{
			flagb=0;
			break;
		}
	}
	if(m==1){
		cout<<maxn;
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(flaga==1){
		sort(a+1,a+n+1,greater<ll>());
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if(flagb==1){
		ll ans=a[n];
		for(int i=n-1;i>=n+1-m;i--){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if(flag4==1){
		sort(a+1,a+n+1,greater<ll>());
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else{
		dfs(1);
		cout<<ans;
	}
	return 0;
}// 4 2 3 15 12 12

