#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500005;
ll a[N];
ll ans[N];
ll vis[N];
int main(){
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ans[a[n]]=n;
	vis[a[n]]=1;
	bool f=0;
	ll end=n;
	for(ll i=n-1;i>=1;i--){
		if(vis[a[i]]==0){
			vis[a[i]]=1;
			for(ll j=i;j<=end-1;j++){
				if(a[i]==a[n])continue;
				ans[a[j]]+=1;
			}
		}
		else{
			f=1;
			if(a[i]==a[n]){
				end=i; 
				continue;
			}
			ans[a[i]]+=1;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
