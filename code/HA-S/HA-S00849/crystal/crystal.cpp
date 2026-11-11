#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
ll n,m;
ll a[N];
ll ans;
ll solve(){
	sort(a+1,a+n+1);
	ll wei,she=m,res=0;
	ll i=1,j=1;
	//i:×ó j:ÓÒ 
	while(i<=n&&j<=n){
		wei=a[j]-a[i];
		she-=(j-i)*(a[j]-a[j-1]);
		while(she<0&&i<j){
			she+=a[j]-a[i];
			i++;
		}
		//ans[j]=j-i+1;
		res=max(res,j-i+1);
		j++;
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	ans=solve();
	printf("%lld",ans);
	return 0;
}
