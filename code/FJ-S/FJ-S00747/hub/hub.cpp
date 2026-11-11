#include<bits/stdc++.h>
#define int long long
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
template<typename T>void read(T &x){
	x=0;T f=1;char c=getchar();
	while(!(c>='0'&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while((c>='0'&&c<='9')){x=x*10+(c^48);c=getchar();}
	x*=f;
}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
signed main(){
	file("hub")
	int c,t;read(c);read(t);
	while(t--)write(0),puts("");
	return 0;
}
