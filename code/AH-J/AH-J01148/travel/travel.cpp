#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) a=1;
	if(a==1&&s1[0]==s2[0]&&s1[1]==s2[1])
		b=1;
	char x,y;
	x=s1[2];
	y=s2[2];
	if(b==1&&(x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C'))
		c=1;
	if(b==1&&(x=='D'||x=='F')&&(y=='D'||y=='F'))
		c=1;
	if(c==1&&(x-1==y||x+1==y))
		d=1;
	cout<<a<<b<<c<<d;
	return 0;
}
