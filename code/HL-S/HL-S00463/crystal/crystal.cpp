#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll inline ret() {
	ll t=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		t=t*10+ch-'0';
		ch=getchar();
	}
	return f*t;
}
ll n,m;
ll a[500009];
bool chat(ll siz){
	ll minm=LLONG_MAX;
	for(ll i=1;i+siz-1<=n;i++){
		ll L=i,R=i+siz-1,t=a[R]-a[R-1];
		ll ans=t*siz-t-a[R-1]+a[L-1];
		minm=min(minm,ans);
		if(minm<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);//fz2021
	freopen("crystal.out","w",stdout);
	n=ret();
	m=ret();
	for(ll i=1;i<=n;i++){
		a[i]=ret();
		a[i]+=10000000000000;
	}
	sort(a+1,a+1+n);
	for(ll i=2;i<=n;i++){
		a[i]+=a[i-1];
	}
	ll L=1,R=n,mid=0,ans=0;
	while(L<=R){
		mid=(L+R)/2;
		if(chat(mid)){
			L=mid+1;
			ans=mid;
		} else {
			R=mid-1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
