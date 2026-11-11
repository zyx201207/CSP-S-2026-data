#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
	return;
}	
int c,n,m,d,q,w[10005];
signed main(){
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k;
		k=read();
		
	}
	return 0;
}
