#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;
bool x,y,xx,yy;
bool check(char aa,char bb){
	if((aa>='A'&&aa<='C'&&bb>='A'&&bb<='C'))return true;
	if((aa>='D'&&aa<='E'&&bb>='D'&&bb<='E'))return true;
	return false;
}
bool ch(char aa,char bb){
	int ta=int(aa),tb=int(bb);
	return abs(ta-tb)==1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=int(c1[0]-48)*10+int(c1[1]-48);
	b=int(s1[0]-48)*10+int(s1[1]-48);
	c=int(c2[0]-48)*10+int(c2[1]-48);
	d=int(s2[0]-48)*10+int(s2[1]-48);
	if(a==c)x=1;
	if(a==c&&b==d)y=1;
	if(a==c&&b==d&&check(s1[2],s2[2]))xx=1;
	if(a==c&&b==d&&check(s1[2],s2[2])&&ch(s1[2],s2[2]))yy=1;
	cout<<x<<y<<xx<<yy;
	return 0;
}
