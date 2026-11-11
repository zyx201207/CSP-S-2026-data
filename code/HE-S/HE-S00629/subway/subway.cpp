#include<bits/stdc++.h>
#define int long long 
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int xdsdg[65];
void write(int x){
	int tot=0;
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x==0){
		putchar('0');return;
	}
	while(x){
		xdsdg[++tot]=((x%10)^48);
		x/=10;
	}
	for(int i=tot;i;i--){
		putchar(xdsdg[i]);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	return 0;
}
