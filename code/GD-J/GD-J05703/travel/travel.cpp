#include <bits/stdc++.h>
using namespace std;

int cr,sr,cx,sx;
string c1,s1,c2,s2;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	int pos=10;
	for(int i=0;i<s1.size()-1;i++) {
		sr+=(s1[i]-'0')*pos;
		pos/=10;
	}
	pos=10;
	for(int i=0;i<s2.size()-1;i++) {
		sx+=(s2[i]-'0')*pos;
		pos/=10;
	}
	
	if(c1==c2) {  
		cout<<'1';
		if(sr==sx) {
			cout<<'1';
			if((s1[2]>'C'&&s2[2]>'C')||(s1[2]<'D'&&s2[2]<'D')) cout<<'1';
			else cout<<'0';
			if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')) cout<<'0';
			else if((s1[2]-1==s2[2])||(s1[2]+1==s2[2])) cout<<'1';
			else cout<<'0';
		} 
		else cout<<"000";
	} 
	else cout<<"0000";
	
	return 0;
} 
