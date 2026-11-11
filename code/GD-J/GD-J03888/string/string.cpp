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
const int N=2e5+100;
ll n,ans;
struct node{
	int num;
	char op;
}li[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	string s="";
	for (int i=1;i<=n;i++){
		li[i].num=read();
		cin>>li[i].op;
		for (int j=1;j<=li[i].num;j++) s+=li[i].op;
	}
//	cout<<s<<'\n';
	for (int i=0;i<s.size();i++){
		if (s[i]!=s[s.size()-i-1])
			ans++;
	}
	write(ans/2);putchar('\n');
//	cout<<(7&1&7)<<'\n';
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

10
a 10
b 8
c 1
d 4
p 9
y 4
r 3
u 10
d 10
u 50
i 5
*/
