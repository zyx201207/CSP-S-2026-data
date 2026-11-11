#include<iostream>
using namespace std;
int a,b,x,y;
char c,z;
int bian(char t)
{
	if(t=='A'||t=='B'||t=='C') return 1;
	else return 0;
}
int main()
{
	cin>>a>>b>>c>>x>>y>>z;
	if(a==x) cout<<1;
	else {cout<<"0000";return 0;}
	if(b==y) cout<<1;
	else {cout<<"000";return 0;}
	if(bian(c)==bian(z)) cout<<1;
	else {cout<<"00";return 0;}
	if(abs(c-z-0)==1) cout<<1;
	else cout<<0;
	return 0;
}
