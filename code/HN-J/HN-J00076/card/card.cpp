#include<bits/stdc++.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
inline char gc(){
	if(p1==p2){
		p2=(p1=buf)+fread(buf,1,1<<21,stdin);
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
const int N=5e5+7,M=3e5+7;
int n,m,a[N],z[M];
long long ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read(),z[a[i]]=i;
	for(int i=1;i<=n;i++)
		for(int j=z[a[i]];j<=n;j++){
			ans[a[j]]++;
			if(j!=z[a[j]]) j=z[a[j]];
		}
	for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0;
}
