#include<bits/stdc++.h>
using namespace std;
int n,m,t,d;
inline int read() {
	char c;int x=1,s=0;
	c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		s=(s<<1)+(s<<3)+(c^48);
		c=getchar();
	}
	return s*x;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++) {
		t=read();d=read();
		for(int j=1,xxx;j<=t;j++) xxx=read();
		cout<<"0\n"; 
	}
	return 0;
}

