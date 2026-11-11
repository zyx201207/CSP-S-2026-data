#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m;
ll a[1000100];
ll dp[200100];
ll ann;
vector<ll> vt;
void dfs(ll x,ll y){
	if(y==m){
		ll t=vt[0];
		for(ll i=1;i<vt.size();i++)t&=vt[i];
		ann=max(ann,t);
		return;
	}
	if(x>n){
		return;
	}
	dfs(x+1,y);
	vt.push_back(a[x]);
	dfs(x+1,y+1);
	vt.pop_back();
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll mm=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		mm=max(mm,a[i]);
	}
	if(m==1){
		ll mx=0;
		for(ll i=1;i<=n;i++)mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}
	else if(m==2){
		ll mx=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	else if(m==n-1){
		ll ans=0;
		for(ll i=1;i<=n;i++){
			ll sum=0;
			for(ll j=1;j<=n;j++){
				if(j==i)continue;
				if(sum==0)sum=a[i];
				else sum=sum&a[i];
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	else if(m==n){
		ll ans=a[1];
		for(ll i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	
	dfs(1,0);
	cout<<ann;
	
//	for(ll i=1;i<=n;i++){
//		for(ll j=m;j>=1;j--){
//			dp[j]=max(dp[j],dp[j-1]&a[i]);
//		}
//	}
//	cout<<dp[m];
	return 0;
}
