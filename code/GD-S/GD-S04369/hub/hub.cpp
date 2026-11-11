#include<bits/stdc++.h>
using namespace std;
const int BUFSIZE=1<<20;
char ibuf[BUFSIZE],*Is=ibuf,*It=ibuf;
inline char gc(){if(Is==It)It=(Is=ibuf)+fread(ibuf,1,BUFSIZE,stdin);return Is==It?EOF:*Is++;}
inline int read(){
	int x=0,f=1;char c=gc();
	while(!isdigit(c)){if(c=='-')f=-1;c=gc();}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=gc();
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}
int c,T,n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1,u,v;i<n;i++)u=read(),v=read();
		write((n-1)/3+1),puts("");
	}
	return 0;
}
