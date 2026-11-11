#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int input();
void print(int x);
signed main(void){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=input(),t=input();
	while (t--){
		int n=input(),m=input()-1;
		while (m--) int u=input(),v=input();
		print(n/2),puts("");
	}
	return 0;
}
inline int input(){
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void print(int x){
	if (x<0){
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
