#include "bits/stdc++.h"
using namespace std;
string c1,s1,c2,s2;
int main(void){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) return cout<<"0000",0;
	if(!(s1[0]==s2[0] && s1[1]==s2[1])) return cout<<"1000",0;
	if(!(('A'<=s1[2] && s1[2]<='C' && 'A'<=s2[2] && s2[2]<='C') || ('D'<=s1[2] && s1[2]<='F' && 'D'<=s2[2] && s2[2]<='F'))) return cout<<"1100",0; 
	if((s1[2]=='A' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='A')) return cout<<"1110",0;
	cout<<"1111";
	fclose(stdin);
	fclose(stdout);
}
