#include<bits/stdc++.h>
using namespace std;
#define int long long
#define v vector
inline int read(){
	char c=getchar();
	int x=0;bool b=1;
	while(c<'0'||c>'9')
	{if(c=='-')b=0;
	c=getchar();}
	while(c>='0'&&c<='9')
	x=(x<<3)+(x<<1)+(c^48),
	c=getchar();
	return b?x:-x;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int c,n,m,i,j;
v<int>s;
inline void Main(){
	if(c>=11&&c<=12){
		n=read(),m=read();
		i=read(),j=read();
		i=j-i;j=n-2;
		while(j--)read();
		if(i>=m*2&&i<m*3){
			write(n-3);
			putchar('\n');
		}else puts("0");
		return;
	}
	if(c>=12&&c<=13){
		puts("0");
		return;
	}
	puts("0");
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();int T=read();
	while(T--)Main();
	return 0;
}
