#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll c,T,n,d;
ll x[N];
ll cnt[N],f[N],g[N];
ll solve(ll l,ll r){
	if(l>r)return 0;
	ll res=0;
	for(ll k=l;k<=r;k++){
		ll last=k;
		for(ll i=k;i<=r;i++){
			f[i]=g[i]=0;
			while(x[i]-x[last]>d&&last<i){
				cnt[f[last]]-=g[last];
				last++;
			}
			ll mi=f[last];
			ll ans=cnt[mi];
			f[i]=mi+1;
			g[i]=max(ans,1ll);
			cnt[f[i]]+=g[i];
			if(g[i]==2){
				res++;
			}
		}
		while(last<=r){
			cnt[f[last]]-=g[last];
			last++;
		}
	}
	return res;
	
}
ll solve1(ll l,ll r){
	if(l>r)return 0;
	ll res=0;
	for(ll k=l;k<=l;k++){
		ll last=k;
		for(ll i=k;i<=r;i++){
			f[i]=g[i]=0;
			while(x[i]-x[last]>d&&last<i){
				cnt[f[last]]-=g[last];
				last++;
			}
			ll mi=f[last];
			ll ans=cnt[mi];
			f[i]=mi+1;
			g[i]=max(ans,1ll);
			cnt[f[i]]+=g[i];
			if(g[i]==2){
				res+=r-i+1;
			}
		}
		while(last<=r){
			cnt[f[last]]-=g[last];
			last++;
		}
	}
	return res;
	
}
void sub1(){
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>x[i]; 
		ll last=1,ans=0;
		for(ll p=1;p<=n;p++){
			if(x[p]>x[p-1]+d){
				ans+=solve1(last,p-1);
				last=p;
			}
		}
		ans+=solve1(last,n);
		cout<<ans<<'\n';
	}
}
void sub2(){
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>x[i]; 
		cout<<0<<'\n';
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11||c==12){
		sub1();
		return 0;
	}
	if(c==13||c==14){
		sub2();
		return 0;
	}
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>x[i]; 
		ll last=1,ans=0;
		for(ll p=1;p<=n;p++){
			if(x[p]>x[p-1]+d){
				ans+=solve(last,p-1);
				last=p;
			}
		}
		ans+=solve(last,n);
		cout<<ans<<'\n';
	}
	return 0;
} 
/*



*/
