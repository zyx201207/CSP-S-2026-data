#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,a[500005],b[500005],ans;

ll read(){
	ll f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
void out(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10)putchar(x+'0');
	else{
		out(x/10);
		putchar(x%10+'0');
	}
}

bool check(ll x){
	ll cnt=0;
	for(ll i=x-1;i>=1;i--){
		cnt+=b[i]*i;
		if(cnt>m)return false;
	}
	return true;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	ll l=0,r=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	out(ans);
	return 0;
}
