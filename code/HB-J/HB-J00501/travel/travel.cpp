#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0,b=0,c=0,d=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;
	}
	a1=s1[0]+s1[1];
	a2=s2[0]+s2[1];
	b1=s1[2];
	b2=s2[2];
	if(a1==a2&&a==1){
		b=1;
	}
	if(b1<="C"&&b2<="C"&&b==1){
		c=1;
	}
	if(b1>="D"&&b2>="D"&&b==1){
		c=1;
	}
	if(b1=="A"&&b2=="B"&&c==1){
		d=1;
	}
	if(b2=="A"&&b1=="B"&&c==1){
		d=1;
	}
	if(b1=="B"&&b2=="C"&&c==1){
		d=1;
	}
	if(b2=="B"&&b1=="C"&&c==1){
		d=1;
	}
	if(b1=="D"&&b2=="F"&&c==1){
		d=1;
	}
	if(b2=="F"&&b1=="D"&&c==1){
		d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
