#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e6+5,mod=1e9+7;
inline ll read(){
	ll f=1,tot=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		tot=tot*10+ch-'0' ;
		ch=getchar();
	}
	return f*tot;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		write(-x);
	}else if(x<10){
		putchar(x+'0');
	}else{
		write(x/10);
		putchar(x%10+'0');
	}
	return ;
}
int c[N],b[N];
ll a[N];
void solve(){
	int n=read();
	ll m=read(),ans=0;
	for(int i=1;i<=n;i++){
		c[i]=0;
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n+1,mid=(l+r)>>1;
		while(l<r-1){
			mid=(l+r)>>1;
			if(a[mid]-a[i]<=m)l=mid;
			else r=mid;
		}
		b[i]=l;
		//cout<<b[i]<<' ';
	}
	for(int i=1;i<=n;i++){
		c[i]+=c[i-1];
		cout<<c[i]<<' ';
		if(b[i]>=i+3){
			ans+=1ll*(b[b[i]-1]-b[b[i]-2])*(c[i]+1);
			c[b[b[i]-1]+1]+=(c[i]+1),c[b[b[i]]+1]-=(c[i]+1);
		}else if(b[i]>=i+2){
			//cout<<b[b[i]-1]<<' ';
			ans+=1ll*(b[b[i]-1]-b[i])*(c[i]+1);
			c[b[b[i]-1]+1]+=(c[i]+1),c[b[b[i]]+1]-=(c[i]+1);
		}else if(b[i]==i+1){
			c[b[i]]+=(c[i]+1),c[b[i]+1]-=(c[i]+1);
		}
//		cout<<ans<<'\n';
//		cout<<'\n';
	}
	write(ans);
	puts(""); 
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1,c=read();
	T=read();
	while(T--)solve();
	return 0;
} 
/*
0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962
*/
