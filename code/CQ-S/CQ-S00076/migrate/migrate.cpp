#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long k=0,p=1,c=getchar();
	while(c!=EOF&&(c>'9'||c<'0')){
		if(c=='-')p*=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*p;
}
void putt(long long x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)putt(x/10);
	putchar(x%10+'0');
}

const long long N=2e6+5;
long long x[N];
long long n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c=read(),T=read();
	while(T--){
		n=read();
		d=read();
		long long di=1e5;
		for(long long i=1;i<=n;i++){
			x[i]=read();
			di=min(x[i]-x[i-1],di);
		}
		if(di>d){
		putchar('0');
		return 0; 
		}
	}
	return 0;
}  
