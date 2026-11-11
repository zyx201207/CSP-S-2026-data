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
ll n,a[N],l,r,lr,rr,ans;
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		cin>>s;
		c[i]=s[0];
	}
	r=n+1;
	while(l<r){
		if(lr>rr){
			r--;rr+=a[r];
			if(c[l]!=c[r]){
				if(rr<=lr)ans+=a[r];
				else ans+=lr-rr+a[r];
			}
		}else{
			l++;lr+=a[l];
			if(c[l]!=c[r]){
				if(rr>=lr)ans+=a[l];
				else ans+=rr-lr+a[l];
			}
		}
	}
	write(ans);
	return 0;
}

