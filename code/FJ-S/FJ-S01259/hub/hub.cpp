#include<bits/stdc++.h>
#define int long long
#ifdef int 
#define inf 0x3f3f3f3f3f3f3f3f
#else 
#define inf 0x3f3f3f3f
#endif
#define ulp(i,a,b) for(int i=a;i<=b;++i)
#define dlp(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
inline int read(){
	char c=getchar();
	bool f=false;
	int num=0;
	while(!isdigit(c)){
		if(c=='-')f=true;
		c=getchar();
	}
	while(isdigit(c)){
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar(); 
	}
	return f?-num:num;
}
void write(int x,char ed=' '){
	if(x<0)putchar('-'),x=-x;
	int stk[65],top=0;
	do{
		stk[++top]=x%10;
		x/=10;
	}while(x);
	while(top)putchar(stk[top--]+'0');
	putchar(ed);
}
#define N 1000005
int n,k;
void solve(){
	n=read(),k=read();
	ulp(i,1,n-1)read(),read();
	write((n-k-1)/3+1,'\n');
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),_=read();
	while(_--)solve();
	return 0;
}
