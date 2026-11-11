#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&(-x))
using namespace std;
const int N=5e5+5,mod=1e9+7;
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
int n;
ll m,a[N],s[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		//cout<<a[i]*x-(s[i]-s[i-x])<<' '<<x<<'\n';
		if(a[i]*x-(s[i]-s[i-x])<=m)return 1;
	}
	return 0;
}
void solve(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int l=1,r=n+1,mid;
	while(l<r-1){
		//cout<<l<<' '<<r<<'\n';
		mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	write(l);
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
	//T=read();
	while(T--)solve();
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/
