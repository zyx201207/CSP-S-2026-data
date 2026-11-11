#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
inline ll read(){
	ll f=1,s=0;
	char t=getchar();
	while(t<'0'||t>'9'){
		if(t=='-') f=-1;
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		s=s*10+t-'0';
		t=getchar();
	}
	return f*s;
} 
inline void write(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const ll N=5e5+10;
ll n,m,s[N];
struct node{
	ll ind,data;
}a[N];
struct lk{
	ll u,v,w;
}d[N];
inline bool cmp(node a,node b){
	return a.data<b.data;
}
inline bool check(ll mid){
	for(ll i=1;i+mid-1<=n;i++){
		if((mid-1)*a[i+mid-1].data-(s[i+mid-2]-s[i-1])<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=n;i++) a[i].data=read(),a[i].ind=i;
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i].data;
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	write(r);
	return 0;
}//Oct31==Dec25?
