#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x){
	x=0;bool bj=0;char s=getchar();
	while(s<'0'||s>'9'){
		if(s=='-')bj=1;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+(s^48);
		s=getchar();
	}
	if(bj)x=-x;
}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(c),read(t);
	while(t--){
		read(n),read(k);
		for(int i=1,u,v;i<n;i++)read(u),read(v);
		write((rand()*c*1ll+rand()*t*1ll+rand()*k*1ll+rand()*n*1ll)%n);
		cout<<"\n";
	}
	return 0;
}
