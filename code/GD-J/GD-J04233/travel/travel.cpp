#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
struct Node{
	int c;
	int line;
	char s;
}a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a.c=c1[1]-'0'+10*(c1[0]-'0');
	a.line=(s1[0]-'0')*10+s1[1]-'0';
	a.s=s1[2];
	b.c=c2[1]-'0'+10*(c2[0]-'0');
	b.line=(s2[0]-'0')*10+s2[1]-'0';
	b.s=s2[2];
	if(a.c==b.c)cout<<"1";
	else cout<<"0";
	if(a.c==b.c and a.line==b.line)cout<<"1";
	else cout<<"0";
	if(a.c==b.c and a.line==b.line and ((a.s>='D' and b.s>='D') or (a.s<='C' and b.s<='C'))){
		cout<<"1";
	}
	else cout<<"0";
	if(abs(a.s-b.s)==1 and a.c==b.c and a.line==b.line and ((a.s>='D' and b.s>='D') or (a.s<='C' and b.s<='C'))){
		cout<<"1";
	}
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
} 
