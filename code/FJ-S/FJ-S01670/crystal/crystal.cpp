#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const ll N=5e5+10;
ll n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for (int i=1;i<=n;i++){
		ll l=1,r=i,pos=-1;
		while(l<=r){
			ll mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m){
				pos=mid;
				r=mid-1;
			} else l=mid+1;
		}
		if(pos==-1) ans=max(ans,1ll);
		else ans=max(ans,i-pos+1);
	}
	printf("%lld\n",ans);
}
//14:44
