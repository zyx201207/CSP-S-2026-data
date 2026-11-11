#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N=5e5+5;
int n,ans=1;
ll m,a[N];
inline ll read(){
	ll x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') y=-1LL;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10LL+(c-'0');
		c=getchar();
	}
	return x*y;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int main(){
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
//	for(int i=2;i<=n;i++){
//		s[i]=s[i-1]+a[i]-a[i-1];
//		co[i]=co[i-1]+(i-1)*(a[i]-a[i-1]);
//	}
	int l=1,r=1;
	ll sum=0;
	while(l<=r&&r<n){
		r++;
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m){
			l++;
			sum-=(a[r]-a[l-1]);
		}
		ans=max(ans,r-l+1);
	}
	write(ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
