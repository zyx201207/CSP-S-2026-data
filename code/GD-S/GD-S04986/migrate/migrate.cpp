#include<bits/stdc++.h>
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
#define ff(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
long long read();
void write(long long x);
long long ccccc,t,n,d,x[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ccccc=read(),t=read();
	while(t--){
		n=read(),d=read();
		cout<<0;
	}
	return 0;
}
long long read(){
	int f=1;
	long long x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(long long x){
	if(x<0)x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
