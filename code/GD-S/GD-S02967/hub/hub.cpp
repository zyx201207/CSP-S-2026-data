#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,fg=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*fg;
}
int t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	t=read();
	while(t--){
		n=read();k=read();
	}
	return 0;
}
