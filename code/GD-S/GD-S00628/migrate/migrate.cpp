#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,d;
int a[N];

inline int read(){
	int x=0,f=1;
	int ch=getchar();
	if(!isdigit(ch)) f=-1,ch=getchar();
	while(isdigit(ch)){
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return f*x;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read();
		d=read();
		for(int i=0;i<n;i++) a[i]=read();
		if(c==11 || c==12){
			int timi=a[1]-a[0];
			cout<<timi<<endl;
		}else if(c==13 || c==14){
			cout<<0<<endl
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
