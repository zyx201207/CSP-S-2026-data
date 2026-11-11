#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int read(){
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9') if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	while(q--) printf("%d",(c+n+m-d+q>0?c+n+m-d+q:c-n-m+d-q));
	return 0;
}
