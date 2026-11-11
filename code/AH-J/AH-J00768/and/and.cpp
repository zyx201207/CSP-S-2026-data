#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m;
ll s[N];
bool vis[N];
ll mx=0;
void dfs(ll cur,ll sum){
	if(cur==m){
		mx=max(mx,sum);
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(cur==0) dfs(cur+1,s[i]);
			else dfs(cur+1,sum&s[i]);
			vis[i]=0;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	ll sum;
	for(ll i=1;i<=n;i++){
		 scanf("%lld",&s[i]);
		 if(i==1) sum=s[i];
		 else sum&=s[i];
	 }
	if(n==m) cout<<sum;
	dfs(0,0);
	cout<<mx;
	return 0;
}
