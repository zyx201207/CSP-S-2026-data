#include<bits/stdc++.h>
using namespace std;
long long c1,s1,c2,s2;
char b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>b1>>c2>>s2>>b2;
	if(b1=='F') b1='E';
	if(b2=='F') b2='E';
	if(c1==c2) cout<<1; else cout<<0;
	if(c1==c2 && s1==s2) cout<<1; else cout<<0;
	if(c1==c2 && s1==s2 
	   && (b1<='C'&&b2<='C' || b1>='D'&&b2>='D') )
	   cout<<1;
	else cout<<0;
	if(c1==c2 && s1==s2 && abs(b1-b2)==1 && 
	   !(b1=='C'&&b2=='D'||b1=='D'&&b2=='C') )
	   cout<<1;
	else cout<<0;
	return 0;
}
