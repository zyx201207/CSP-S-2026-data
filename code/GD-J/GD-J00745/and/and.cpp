#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
const int N=2e5+100;
ll n,m;
ll a[N],b[N];
bool used[N]={false};
ll ans=-2e18;
void dfs(ll id){
	if(id>m){
		ll cnt=b[1];
		for(ll i=2;i<=m;i++){
			cnt&=b[i];
		}
		ans=max(ans,cnt);
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!used[a[i]]){
			b[id]=a[i];
			used[a[i]]=true;
			dfs(id+1);
			used[a[i]]=false;
		}
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
