#include<bits/stdc++.h>
using namespace std;
#define us unsigned
#define ll long long
#define pb emplace_back
#define il inline
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
inline ll read(){
	ll num=0;bool f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=0;c=getchar();}
	while(c>='0' && c<='9')num=num*10+(c^48),c=getchar();
	return f?num:-num;
}
const ll N=4e5+5;
ll n;
struct node{
	ll cnt,val;
}a[N],b[N];
int main(){
	//ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	For(i,1,n){
		a[i].cnt=read();
		char c=getchar();
		while(c<'a' ||  c>'z')c=getchar();
		a[i].val=c-'a'+1;
	}
	For(i,1,n)b[i]=a[n-i+1];
	ll now=1,sum=0,ans=0;
	For(i,1,n){
		sum=0;
		while(now<=n){
			if(sum+b[now].cnt<=a[i].cnt){
				sum+=b[now].cnt;
				if(b[now].val!=a[i].val)ans+=b[now].cnt;
				++now;
			}
			else{
				ll x=a[i].cnt-sum;
				if(b[now].val!=a[i].val)ans+=x;
				b[now].cnt-=x;
				break;
			}
		}
	}
	printf("%lld",ans/2);
	return 0;
}


