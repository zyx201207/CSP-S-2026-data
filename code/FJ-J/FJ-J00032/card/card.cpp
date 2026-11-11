#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,a[500001],b[300001],c[300001],w;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
bool f;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	cout<<n;
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
