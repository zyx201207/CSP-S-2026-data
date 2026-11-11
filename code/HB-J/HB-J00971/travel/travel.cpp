#include <bits/stdc++.h>
using namespace std;
bool ce(string a,string b){
	if(a[2]=='A'&&(b[2]=='B'||b[2]=='C'))return true;
	if(a[2]=='B'&&(b[2]=='A'||b[2]=='C'))return true;
	if(a[2]=='C'&&(b[2]=='B'||b[2]=='A'))return true;
	if(a[2]=='D'&&b[2]=='F')return true;
	if(a[2]=='F'&&b[2]=='D')return true;
	return false;
}
bool ce2(string a,string b){
	if(a[2]=='A'&&b[2]=='B')return true;
	if(a[2]=='B'&&(b[2]=='A'||b[2]=='C'))return true;
	if(a[2]=='C'&&b[2]=='B')return true;
	if(a[2]=='D'&&b[2]=='F')return true;
	if(a[2]=='F'&&b[2]=='D')return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.in","r",stdout);
	string c1,s1,c2,s2;
	int z1=0,z2=0,z3=0,z4=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<z1<<z2<<z3<<z4;
		return 0;
	}
	else{
		z1=1;
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			z2=0;
		}
		else{
			z2=1;
			if(ce(s1,s2)){
				z3=1;
		}
			if(ce2(s1,s2)){
				z4=1;
			}
		}
	}
	cout<<z1<<z2<<z3<<z4;
	return 0;
}
