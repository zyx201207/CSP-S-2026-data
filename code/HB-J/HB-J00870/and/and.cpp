#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[200010];
bool vis[200010];
ll ans=0;
ll n,m;

void check(){
	ll vissum=0;
	for(ll i=1;i<=n;i++){
		if(vis[i]==1){
			vissum++;
		}
	}
	if(vissum!=m){return;}
	
	ll flag=0;
	for(ll i=1;i<=n;i++){
		if(vis[i]==1){
			flag=i;
			break;
		}
	}
	ll sumn=arr[flag];
	for(ll i=1;i<=n;i++){
		if(vis[i]==1){
			sumn&=arr[i];
		}
	}
	
	ans=max(ans,sumn);
	return;
}

void dfs(int now){
	if(now==n+1){
		check();
		return;
	}
	vis[now]=1;
	dfs(now+1);
	vis[now]=0;
	dfs(now+1);
}

void solve(){ 
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>arr[i];
	
	if(n<=20){dfs(1);cout<<ans;}
	else if(m==n){
		ll sumn=arr[1];
		for(int i=2;i<=n;i++){
			sumn&=arr[i];
		}
		cout<<sumn;
	}else if(m==1){
		ll maxn=-1;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,arr[i]);
		}
		cout<<maxn;
	}else if(m==2){
		ll maxn=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(i==j) continue;
				maxn=max(maxn,arr[i]&arr[j]);
			}
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
    //ios::sync_with_stdio(false);
	//cin.tie(nullptr);cout.tie(nullptr);
	
	solve();
	
	fclose(stdin);
   	fclose(stdout);
	return 0;
}
// 3 10:23 -- wcqk HB-J00870
