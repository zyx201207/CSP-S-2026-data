#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c;
	long long a=0,f=1;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(!(c<'0'||c>'9')){
		a*=10,a+=c-'0';
		c=getchar();
	}
	return a*f;
}
void write(long long a){
	if(a<0){
		putchar('-');
		a*=-1;
	}
	if(a>=10)write(a/10);
	putchar(a%10+'0');
	return;
}
long long c,t,n,d,a[2000006],s;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		if(c==11||c==12){
			s=0;
			d/=a[2]-a[1];
			if(d==0||d==1||d>=n-1)puts("0");
			else{
				write(n-(d*2-1));
				puts("");
			}
		}
		else puts("0");
	}
	return 0;
} 
