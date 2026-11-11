#include<iostream>
#include<cstdio>
using namespace std;
string c1,s1,c2,s2,d1,d2,e1,e2;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	d1=s1[0]+s1[1];
	d2=s2[0]+s2[1];
	e1=s1[2];
	e2=s2[2];
	if(c1==c2) a=1;
	else{
		cout<<"0000";
		return 0;
	} 
	if(d1==d2) b=1;
	else{
		cout<<"1000";
		return 0;
	}
	if(e1<"D"&&e2<"D"||e1>="D"&&e2>="D") {
		if(e1>="D"&&e2>="D"){	
			cout<<"1111";
			return 0;
		}
	}
	else{
		cout<<"1100";
		return 0;
	}
	if(e1=="A"&&e2=="B"||e1=="B"&&e2=="C"||e1=="B"&&e2=="A"||e1=="C"&&e2=="B") cout<<"1111";
	else cout<<"1110";
	return 0;	
}
