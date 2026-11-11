#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,K=1e6+5;
int c,t,n,k;
int read() {
	int k=0,f=1,c=getchar();
	for(; !isdigit(c); c=getchar()) if(c=='-') f=-1;
	for(; isdigit(c); c=getchar()) k=k*10+c-'0';
	return k*f;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--) {
		n=read(),k=read();
		for(int i=1; i<=n-1; i++) {
			int u=read(),v=read();
		}
		if(k>=n-3) {
			printf("0\n");
			continue;
		}
		else {
			printf("1\n");
		}
	}
	return 0;
}
