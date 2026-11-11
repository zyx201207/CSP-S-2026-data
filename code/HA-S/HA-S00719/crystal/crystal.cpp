#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define pc putchar
typedef long long ll;
const int N=5e5+5;
ll read(){
	ll x=0; bool f=1;
	char c=gc();
	while(c>'9'||c<'0'){
		if(c=='-') f=0;
		c=gc();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=gc();
	}
	return f?x:-x;
}
void put(ll x){
	if(x<0){x=-x;pc('-');}
	if(x>9)put(x/10);
	pc(x%10+'0');
}
ll a[N],s[N],n,m;
bool check(ll l,ll r){
	return m>=( (r-l+1)*a[r]-(s[r]-s[l-1]) );
}
ll ef(ll l,ll r){
	ll R=r,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid,R)) r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	ll ans=0;
	for(int i=1;i<=n;++i){
		ll l=ef(1,i);
		ans=max(ans,i-l+1);
	}
	put(ans);
	return 0;
}
