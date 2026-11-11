#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10,inf=1e15,md=1e9+7;
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
ll n,m,ans;
struct ss{
	ll lst,nxt,a;
}a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i].a=read();
		a[i].lst=i-1;
		a[i].nxt=i+1;
	}
	a[0].nxt=1;a[n+1].lst=n;
	for(ll j=29;j>=0;j--){
		ll sum=0;
		for(ll i=a[0].nxt;i!=n+1;i=a[i].nxt)
			if((1ll<<j)&a[i].a)sum++;
		if(sum>=m){
			ans+=(1ll<<j);
			for(ll i=a[0].nxt;i!=n+1;i=a[i].nxt)
			if(!((1ll<<j)&a[i].a)){
				a[a[i].lst].nxt=a[i].nxt;
				a[a[i].nxt].lst=a[i].lst;
			}
		}
	}
	write(ans);
	return 0;
}

