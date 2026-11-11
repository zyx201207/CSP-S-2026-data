#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll read(){
	ll ans=0,w=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-'){
			w=-w;
		}
		s=getchar();
	}
	while(isdigit(s)){
		ans=(ans<<3LL)+(ans<<1LL)+(s^48);
		s=getchar(); 
	}
	return ans*w;
}

const int N=5e5+10;
ll n,m,a[N];
ll pre[N];

ll query(ll l,ll r){
	return pre[r]-pre[l-1];
}

ll get(ll l,ll r){
	return a[r]*(r-l+1)-query(l,r);
}

bool check(ll x){
	for(ll r=x;r<=n;r++){
		ll l=r-x+1;
		if(get(l,r)<=m){
			return true;
		}
	}
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	
	ll l=2,r=n,ans=1;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	
	printf("%lld\n",ans); 
	
	return 0;
}
