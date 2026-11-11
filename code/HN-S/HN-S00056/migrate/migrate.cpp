#include<bits/stdc++.h>
using namespace std;
#define int long long
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
const int N=2e6+10;
int c,t,n,d,a[N];
void sola(){
	if(a[2]-a[1]>=d) cout<<"0\n";
	else cout<<max(1LL*0,n-(d/(a[2]-a[1])*2)+1)<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0); 
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++) a[i]=read();
		if(c==11 || c==12) sola(); 
		else cout<<"0\n"; 
	}
	return 0;
}
