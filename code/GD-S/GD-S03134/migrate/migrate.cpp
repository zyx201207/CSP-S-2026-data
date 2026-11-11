#include<bits/stdc++.h>
#define int long long
#ifdef __unix
#define getchar getchar_unlocked
#define putchar putchat_unlocked
#else
#define getchar _getchar_nolock
#define putchar _putchar_nolock
#endif
using namespace std;
int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
void write(int x){
	if(x==0) putchar('0');
	else{
		int pos=0;char stk[30]={0};
		while(x) stk[pos++]=x%10+'0',x/=10;
		while(pos--) putchar(stk[pos]);
	}putchar('\n');
}
const int N=2e6+10;
int T,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	T=read(),T=read();
	while(T--){
		int n=read(),d=read();
		for(int i=1;i<=n;i++) a[i]=read();
		int k=a[2]-a[1];
		if(2*k>d) write(0);
		else{
			int x=(n+1)/k;
			write(x);
		}
	}
	return 0;
}

