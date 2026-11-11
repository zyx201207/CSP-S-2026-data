#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d,e;
int o;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(s1[2]=='A'||s1[2]=='B'||s1[2]=='C');
	b=(s2[2]=='A'||s2[2]=='B'||s2[2]=='C');
	c=(c1==c2)?1:0;
	d=(c&&s1[1]==s2[1])?1:0;
	e=(c&&d&&a==b)?1:0;
	o=s1[2]-s2[2];
	cout<<c;
	cout<<d;
	cout<<e;
	cout<<((e&&(o==1||o==-1))?1:0);
	return 0;
} 
