#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,x[N];
long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f = -f;
		c = getchar();
	}
	while(isdigit(c)){
		x = (x<<3)+(x<<1)+(c^48);
		c = getchar();
	}
	return x*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read();
	t = read();
	while(t--){
		long long n=read(),d=read();
		for(int i=1;i<=n;i++) x[i] = read();
		if(c==11 || c==12 || c==0){
			if(d<x[3]-x[1]) cout << "0\n";
			else cout << n-d/abs(x[1]-x[2])-1 << '\n'; 
		}
	}
	return 0;
}
