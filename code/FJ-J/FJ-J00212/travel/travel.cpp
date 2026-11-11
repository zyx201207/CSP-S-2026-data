#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
char s,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>s1>>s2>>c1>>c2;
	if(s1==c1) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s2[0]==c2[0] && s2[1]==c2[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	s=s2[2];
	c=c2[2];
	bool o=0;
	if(s=='A'){
		if(c=='B' || c=='C') o=1;
	}
	else if(s=='B'){
		if(c=='C' || c=='A') o=1;
	}
	else if(s=='C'){
		if(c=='B' || c=='A') o=1;
	}
	else if(s=='D'){
		if(c=='E') o=1;
	}
	else if(s=='E'){
		if(c=='D') o=1;
	}
	if(o) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	o=0;
	if(s=='A'){
		if(c=='B') o=1;
	}
	else if(s=='B'){
		if(c=='C' || c=='A') o=1;
	}
	else if(s=='C'){
		if(c=='B') o=1;
	}
	else if(s=='D'){
		if(c=='E') o=1;
	}
	else if(s=='E'){
		if(c=='D') o=1;
	}
	if(o) cout<<1;
	else{
		cout<<"0";
		return 0;
	}
	return 0;
} 
