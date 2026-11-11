#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

string c1,c2,s1,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1>s2){
		string t;
		t=s1;
		s1=s2;
		s2=t;
		t=c1;
		c1=c2;
		c2=t;
	}
	bool ba,bb,bc,bd;
	ba=bb=bc=bd=false;
	if(c1==c2) ba=true;
	else ba=false;
	if(ba && s1[1]==s2[1]) bb=true;
	else bb=false;
	if(bb && ((s1[2]<='C' && s2[2]<='C') || (s1[2]>'C' && s2[2]>'C'))) bc=true;
	else bc=false;
	if(bc && ((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='D' && s2[2]=='F'))) bd=true;
	else bd=false;
	printf("%d%d%d%d",ba,bb,bc,bd);
}