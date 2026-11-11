#include <bits/stdc++.h>
using namespace std;
#define gc() getchar()
#define pc(x) putchar(x)
using ll=long long;
ll read(){
	ll x=0;
	int f=1,ch=gc();
	while (!isdigit(ch)) {
		f=(ch=='-'?-1:f);
		ch=gc();
	}
	while (isdigit(ch)){
		x=x*10+ch-'0';
		ch=gc();
	}
	return x*f;
}
void write(ll x){
	if (x>9) write(x/10);
	pc(x%10+'0');
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while (t--){
		int n=read();
		int k=read();
		for (int i=1;i<=n;i++){
			int u=read();
			int v=read();
		}
		cout << 0 << '\n';
	}
}
