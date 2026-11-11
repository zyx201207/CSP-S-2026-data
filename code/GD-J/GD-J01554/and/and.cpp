#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[200005];
void m_1(){
	ll mx=-1e18;
	for(ll i=1;i<=n;i++){
		mx=max(mx,a[i]);
	}
	cout<<mx;
}
void m_n(){
	ll ans=a[1];
	for(ll i=2;i<=n;i++){
		ans=ans&a[i];
	}
	cout<<ans;
}
void m_2(){
	ll mx=-1e18;
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			mx=max(mx,a[i]&a[j]);
		}
	}
	cout<<mx;
}
void n_20(){
	ll N=pow(2,n),mx=-1e18;
	for(ll i=1;i<=N-1;i++){
		ll ans=-1e18,cnt=0;
		for(ll j=1;j<=n;j++){
			if(1&(i>>j-1)){
				if(ans==-1e18) ans=a[j];
				else ans=ans&a[j];
				cnt++;
			}
		}
		if(cnt==m) mx=max(mx,ans);
	}
	cout<<mx;
}
ll count1(ll i){
	ll cnt=0;
	for(ll j=1;j<=64;j++){
		if(1&(i>>j-1)){
			cnt++;
		}
	}
	return cnt;
}
void solve(){
	sort(a+1,a+n+1,[](ll x,ll y){
		return count1(x)>count1(y);
	});
	ll ans=a[1];
	for(ll i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		m_1();
	}else if(m==n){
		m_n();
	}else if(m==2 and n<=10000){
		m_2();
	}else if(n<=20){
		n_20();
	}else{
		solve();
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
