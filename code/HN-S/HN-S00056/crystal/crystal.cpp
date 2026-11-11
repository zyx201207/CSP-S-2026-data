#include<bits/stdc++.h>
using namespace std;
#define int long long
char buf[1<<21],*p1=buf,*p2=buf;
inline char gc(){
	if(p1==p2){
		p2=(p1=buf)+fread(buf,1,1<<1,stdin);
		if(p1==p2) return EOF;
	}
	return *p1++;
}
inline int read(){
	int x=0,f=1;
	char c=gc();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=gc(); 
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=gc();
	}
	return x*f;
}
const int N=5e5+10;
int n,m,a[N],s[N];
bool check(int x){
	for(int i=1;i<=n-x+1;i++)
		if((x-1)*a[i+x-1]-s[i+x-2]+s[i-1]<=m) return 1;
		return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
