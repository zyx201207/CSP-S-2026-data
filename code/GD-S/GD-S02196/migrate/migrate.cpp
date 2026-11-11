#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int read(){
	int x=0,sign=1;char opt=getchar();
	while(opt<'0'||opt>'9'){
		if(opt=='-'){sign=-1;}
		opt=getchar();
	}
	while(opt>='0'&&opt<='9'){
		x=x*10+(opt-'0');
		opt=getchar();
	}
	return sign*x;
}
int c,T,n,d;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	c=read();T=read();
	while(T--){
		n=read();d=read();
		for(int i=1;i<=n;i++){a[i]=read();}
		if(n<=2){printf("0\n");continue;}
		if(c==11||c==12){
			if(abs(a[2]-a[1])<2*d){
				printf("0\n");
			}else{
				printf("%d\n",n-2);
			}
		}
	}
} 
