#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
inline long long read(){
	long long f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		int n;
		long long d,x[N];
		n=read();d=read();
		for(int i=1;i<=n;++i)
			x[i]=read();
		int w=x[2]-x[1];
		if(w>=d||2*w>d||d>=w*3){
			cout<<0<<"\n";
			continue;
		}
		if(d>=2*w&&d<w*3){
			cout<<n-3<<"\n";
			continue;
		}
		else cout<<0<<"\n";
	}
	return 0;
}

