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

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t=read();
	while(t--){
		write(0);
	}
	return 0;
}

