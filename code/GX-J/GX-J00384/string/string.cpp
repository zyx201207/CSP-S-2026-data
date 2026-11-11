#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
inline void print(long long x){
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
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=read();
	string s="";
	while(n--){
		int x=read();
		char c=getchar();
		while(c<'a'||c>'z')c=getchar();
		while(x--) s+=c;	
	}
	n=s.size()-1;
	long long cnt=0;
	for(int i=0;i<=n/2;++i)
		if(s[i]!=s[n-i])
			++cnt;
	print(cnt);
	return 0;
}
