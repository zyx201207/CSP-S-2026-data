#include<bits/stdc++.h>
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define int long long
#define IOimprove ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;T f=1;char c=getchar();
	while(!(c>='0'&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,a[222222],b[222222];
char c;
signed main(){
	file("string")
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);c=getchar();
		b[i]=c-'a'+1;
	}
	int l=1,r=n,reml=a[1],remr=a[n],cl=b[1],cr=b[n],ans=0;
	while(l<r){
		int g=min(reml,remr);
		if(cl!=cr)ans+=g;
		reml-=g;remr-=g;
		if(reml==0){
			cl=b[++l];
			reml=a[l];
		}
		if(remr==0){
			cr=b[--r];
			remr=a[r];
		}
	}
	write(ans);puts("");
	return 0;
}
