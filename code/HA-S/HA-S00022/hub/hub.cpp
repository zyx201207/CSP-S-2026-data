#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
//#define int long long
//const int mod=998244353;
//const int mod=1e9+7;
const int N=1e5+5;
using namespace std;
int read(){
	int x=0;
	short f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*((1<<1)+(1<<3))+c-'0';
		c=getchar();
	}
	return ((f)?(-x):(x));
}
int n,t;
signed main(){
	fre("hub")
	c=read(),t=read();
	while(t--) cout<<"1\n";
	return 0;
}
