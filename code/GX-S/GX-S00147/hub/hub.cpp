#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
inline void print(int x){
	stack<char> s;
	do{
		s.push(x%10+'0');
		x/=10;	
	}while(x);
	while(!s.empty()){
		putchar(s.top());		
		s.pop();	
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int t=read();
	t=read();
	for(int i=1;i<=t;++i)print(rand());
	return 0;
}
