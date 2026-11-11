#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE 1
#define duoce 0
typedef long long ll;
const int N=2e5+5;
void solve();
inline ll read(){
	ll ret=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	if(ONLINE_JUDGE){
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
	}
	else{
		freopen("string4.in","r",stdin); 
	} 
	int t=1;
	if(duoce)t=read();
	while(t--)solve();
}
ll a[N];
ll sum[N];
char c[N];
void solve(){
	ll n;
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		sum[i]=sum[i-1]+a[i];
		c[i]=getchar();
	}
	int pos=lower_bound(sum+1,sum+n+1,(sum[n]+1)/2)-sum;
	ll ans=0;
	if(sum[n]&1){
		//pos就是最中间的点所在的块
		//设最中间的点(sum[n]+1)/2=x 
		//首先，对于这个块内，
		//max(sum[pos-1],2*x-sum[pos])~x~min(sum[pos],x-sum[pos-1]-1+x) 
		//这些块是一定相等的
		//然后我们继续找，令l=max(sum[pos-1],2*x-sum[pos])-1;
		//r=min(sum[pos],x-sum[pos-1]-1+x)+1;
		//接着找到他们对应的块数
		//对于每一个块，看他们的c是否相等
		//如果相等，继续找到最远的c相等的点
		//然后更新l,r
		//直到l=0。 
		//如何更新l,r？
		//设lk,rk。
		//显然两块对应的最小区域就是max(sum[lk-1]+1,2*x-sum[rk])~min(sum[rk],2*x-sum[lk-1]-1) 
		ll x=(sum[n]+1)/2;
		ll l=x-1;
		ll r=x+1;
		int lk=lower_bound(sum+1,sum+n+1,l)-sum;
		int rk=lower_bound(sum+1,sum+n+1,r)-sum;
		ll ql,qr;
		while(l>0){
			ql=max(sum[lk-1]+1,2*x-sum[rk]);
			qr=min(sum[rk],2*x-sum[lk-1]-1);
			if(c[lk]!=c[rk]){
				ans+=(l-ql+1);
			}
			l=ql-1;
			if(l<sum[lk-1]+1)lk--;
			r=qr+1;
			if(r>sum[rk])rk++;
		}
		write(ans);
	}
	else{
		/*
		如果是偶数个，那么显然初始的时候是l=x,r=x+1
		*/
		ll x=(sum[n]+1)/2;
		ll l=x;
		ll r=x+1;
		int lk=lower_bound(sum+1,sum+n+1,l)-sum;
		int rk=lower_bound(sum+1,sum+n+1,r)-sum;
		ll ql,qr;
		while(l>0){
			ql=max(sum[lk-1]+1,2*x-sum[rk]);
			qr=min(sum[rk],2*x-sum[lk-1]-1);
			if(c[lk]!=c[rk]){
				ans+=(l-ql+1);
			}
			l=ql-1;
			if(l<sum[lk-1]+1)lk--;
			r=qr+1;
			if(r>sum[rk])rk++;
		}
		write(ans);
	}
}
/*
*/
