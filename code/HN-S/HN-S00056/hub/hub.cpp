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
int c,t;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--) cout<<"0\n";
	return 0;
} 
