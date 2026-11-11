#include<bits/stdc++.h>
using namespace std;
string c[10];
int a,b,x,y,l,r;
char s,t;
bool fa,fb,fc,fd;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>c[2]>>c[3]>>c[4];
	if(c[1][0]=='0') a=c[1][1]-'0';
	else a=c[1][1]-'0'+10;
	if(c[2][0]=='0') b=c[2][1]-'0';
	else b=c[2][1]-'0'+10;
	if(c[3][0]=='0') x=c[3][1]-'0';
	else x=c[3][1]-'0'+10;
	if(c[4][0]=='0') y=c[4][1]-'0';
	else y=c[4][1]-'0'+10;
	s=c[2][2];
	l=(s-'A'<3);
	t=c[4][2];
	r=(t-'A'<3);
	fa=(a==x);
	fb=(fa&&b==y);
	fc=(fb&&(l==r));
	fd=(fc&&((s-t>0&&s-t<2)||(-s+t>0&&-s+t<2)));
	printf("%d%d%d%d",fa,fb,fc,fd);
	return 0;
}
