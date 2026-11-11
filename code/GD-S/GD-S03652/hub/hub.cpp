#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e6+5,mod=1e9+7;
inline ll read(){
	ll f=1,tot=0;char ch=getcahr();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		tot=tot*10+ch-'0' ;
		ch=getchar();
	}
	return f*tot;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		write(-x);
	}else if(x<10){
		putchar(x+'0');
	}else{
		write(x/10);
		putchar(x%10+'0');
	}
	return ;
}
void solve(){
	return ;
}
int main(){
	int T=1;
	//T=read();
	while(T--)solve();
	return 0;
} 
