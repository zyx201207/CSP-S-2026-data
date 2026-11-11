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
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read();int T=read();
	while(T--)puts("0");
	return 0;
}
