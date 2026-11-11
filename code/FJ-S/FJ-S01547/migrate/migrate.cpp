#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
long long readll(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
long long x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	c=read();
	t=read();
	while(t--){
		long long n,d;
		n=readll();
		d=readll();
		for(int i=0;i<n;i++){
			x[i]=readll();
		}
		long long cha=x[1]-x[0];
		if(d<cha*2){
			printf("0\n");
			continue;
		}
		long long cnt=d/cha;
		cnt*=2;
		long long ans=n-cnt+1;
		if(ans<0||cnt<2){
			ans=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
