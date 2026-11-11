#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10,inf=1e15,md=1e9+7;
ll read(){
	ll ans=0,f=1;
	char s=' ';
	while(!(s>='0'&&s<='9')){
		s=getchar();
		if(s=='-')f=-1;
	}
	while(s>='0'&&s<='9'){
		ans=ans*10+s-'0';
		s=getchar();
	}
	return ans*f;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar('0'+x%10);
}
ll n,m,a[N],s[N],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(ll i=2;i<=n;i++){
		ll l=1,r=i;
		while(l<=r){
			ll mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m){
				r=mid-1;
				ans=max(ans,i-mid+1);
			}else l=mid+1;
		}
	}
	write(ans);
	return 0;
}

