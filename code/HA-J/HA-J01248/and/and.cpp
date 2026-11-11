#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
ll n,m,a[N],sum,ans[N],f; 

ll qwq(ll i,ll x,ll de){
	if(n-de<m) return 0;
	
	if(i==m) return max(x&a[i],x);
	return max(qwq(i+1,x&a[i],de),qwq(i,x,de+1));
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
		f=max(f,a[i]);
		if(i==1) sum=a[i];
		else sum&=a[i];
	}
	
	if(m==1){
		cout<<f;
		return 0;
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	if(m==2 && n<=5000){
		ll ma=0;
		for(ll i=1;i<=n;++i){
			for(ll j=i+1;j<=n;++j){
				ll x=a[i]&a[j];
				ma=max(ma,x);
			}
		}
		cout<<ma;
		return 0;
	}
	if(n<=20){
		ll ma=qwq(1,a[1],0);
		cout<<ma;
	}
	
	
	ll p=1;
	for(ll i=1;i<=n;++i){
		p*=2;
		if(p<=n && p/2>=m){
			cout<<p/2;
			return 0;
		}
	}
	if((n+1)/2>=m){
		cout<<1;
	}else{
		cout<<0;
	}
	
	return 0;
}
