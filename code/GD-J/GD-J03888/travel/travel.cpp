#include<bits/stdc++.h>
using namespace std;
#define ll long long

inline int read(){
	int a=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		a=(a<<3)+(a<<1)+(ch-'0');
		ch=getchar();
	}
	return a*f;
}
inline void write(int a){
	if (a<0){
		a=-a;
		putchar('-');
	}
	if (a>=10) write(a/10);
	putchar(a%10+'0');
}
string c,s,c2,s2;
bool g(char a,char b){
	if (a<='C'&&b<='C'||a>'C'&&b>'C') return true;
	else return false;
}
bool f(int a,int b){
	char x=char(a+'A'),y=char(b+'A');
//	cout<<x<<' '<<y<<
	if (x=='A'&&y=='B'||x=='B'&&y=='C'||x=='D'&&y=='F')
		return true;
	else
		return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c2>>s2;
	bool l=false;
	if (c==c2){
		putchar('1');
		l=true;
	}
	else putchar('0');
	bool p=false;
	if (l&&s[0]==s2[0]&&s[1]==s2[1]){
		putchar('1');
		p=true;
	}
	else putchar('0');
	if (p&&g(s[2],s2[2])){
		putchar('1');
	}
	else
		putchar('0');
	if (p&&f(min(s[2]-'A',s2[2]-'A'),max(s[2]-'A',s2[2]-'A'))){
		putchar('1');
	}
	else
		putchar('0');
	return 0;
}
/*
Trick||Treat!
*/
