#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,T,n;
long long d,a[N];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch!=EOF&&(ch<'0'||ch>'9')) { if(ch=='-') f=-1; ch=getchar(); }
	while(ch!=EOF&&(ch>='0'&&ch<='9')) { x=x*10+ch-48; ch=getchar(); }
	return x*f;
}
inline long long read_ll(){
	long long x=0,f=1;char ch=getchar();
	while(ch!=EOF&&(ch<'0'||ch>'9')) { if(ch=='-') f=-1; ch=getchar(); }
	while(ch!=EOF&&(ch>='0'&&ch<='9')) { x=x*10+ch-48; ch=getchar(); }
	return x*f;
}
int main()
{
	c=read();T=read();
	while(T--){
		n=read();d=read_ll();
		for(int i=1;i<=n;i++) a[i]=read_ll();
		
	}

	return 0;
}

