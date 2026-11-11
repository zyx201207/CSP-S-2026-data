#include <iostream>
#include <cstdio>
using namespace std;
string c1,c2,s1,s2;
int f(string s) {
	int x=int(s[0]-'0');
	x*=10;
	x+=int(s[1]-'0');
	return x;
}
bool g(char a,char b) {
	if(a>='A'&&a<='C'&&b>='A'&&b<='C')
	return true;
	if(a>='D'&&a<='F'&&b>='D'&&b<='F')
	return true;
	return false;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) {
		cout<<"0000";
		return 0;
	}
	cout<<1;
	int x=f(s1),y=f(s2);
	if(x!=y) {
		cout<<"000";
		return 0;
	}
	cout<<1;
	char cx=s1[2],cy=s2[2];
	if(!g(cx,cy)) {
		cout<<"00";
		return 0;
	}
	cout<<1;
	if((int(cx-cy)==1)||(int(cy-cx)==1))
	cout<<1;
	else cout<<0; 
	return 0;
}