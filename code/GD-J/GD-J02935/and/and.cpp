#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
inline ll read(){
	ll f=1,s=0;
	char t=getchar();
	while(t<'0'||t>'9'){
		if(t=='-') f=-1;
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		s=s*10+t-'0';
		t=getchar();
	}
	return f*s;
}
inline void write(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const ll N=2e5+10;
ll n,m,ans,a[N],ansmask;
inline bool cmp(ll a,ll b){
	return a>b;
}
inline void solve2(){
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(ll i=2;i<=m;i++){
		ans&=a[i];
	}
	write(ans);
}
inline void solve1(){
	for(ll mask=1;mask<=(1<<n)-1;mask++){
		ll sum=0,cnt=0;
		for(ll j=0;(1<<j)<=mask;j++){
			if((1<<j)&mask){
				cnt++;
				if(sum==0) sum=a[j+1];
				else sum&=a[j+1];
			} 
		}
		if(cnt==m){
			if(sum>ans) ans=sum,ansmask=mask;
		} //ans=max(ans,sum);
	}
	write(ans);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	if(n>2000) solve2();
	else solve1();	
	return 0;
}
//Trick||Treat!
