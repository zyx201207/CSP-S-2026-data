#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=1,b=1,c=1,d=1;
	if(c1!=c2){
		a=0;
		b=0;
		c=0;
		d=0;
	}
	int ss1=0,ss2=0;
	ss1=int(s1[0])*10+int(s1[1]=1);
	ss2=int(s2[0])*10+int(s2[1]=1);
	if(ss1!=ss2){
		b=0;
		c=0;
		d=0;
	}
	int cs1,cs2;
	cs1=(int)s1[2];
	cs2=(int)s2[2];
	if((cs1%5<=2&&cs2%5>2)||(cs2%5<=2&&cs1%5>2)){
		c=0;
		d=0;
	}
	if((cs1-cs2)*(cs1-cs2)!=1){
		d=0;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
