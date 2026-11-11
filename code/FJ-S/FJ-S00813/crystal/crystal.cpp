#include <iostream>
#include <algorithm>

#define ll long long
#define gc getchar()
using namespace std;
const int MAXN=5e5+114;
 

inline ll read(){
	ll p=0,k=1;
	char c=gc;
	while (c<'0'||c>'9') {
		if(c=='-') k=-k;
		c=gc;
	}
	while (c>='0'&&c<='9') p=p*10+c-'0',c=gc;
	return p*k;
}
ll n,m;
ll a[MAXN];
ll s[MAXN];
bool cmp(ll a,ll b){
	return a<b;
}

ll check(ll id){
	ll l=1,r=id-1; // ¹Ì¶¨µãid-1 
	while (l<r){
		ll mid=(l+r)>>1;
		ll len=id-mid;
		if(len*a[id]-(s[id-1]-s[mid-1]) <=m) r=mid;
		else l=mid+1;
	} 
	return id-l+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n,cmp);
	
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll ans=0;
	for (int i=1;i<=n;i++) 
		ans=max(ans,check(i));
	cout<<ans;
	return 0;
}
