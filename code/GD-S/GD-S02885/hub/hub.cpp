#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N=1e5+5;

inline int read(){
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*y;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	write(x%10+'0');
}
int main(){
//	freopen("subway4.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=0,t=0;
	c=read(); t=read();
	int sum=0;
	while(t--){
		cout<<++sum<<"\n";
	}
	return 0;
}

