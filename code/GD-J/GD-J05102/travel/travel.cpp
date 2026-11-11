#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout); 
	string s1,s2;
	int c1,c2,s=1;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)s=0;
	cout<<s;
	if(s1[0]!=s2[0])s=0;
	if(s1[1]!=s2[1])s=0;
	cout<<s;
	s=0;
	if(s1[2]=='A'){
		if(s2[2]=='B')s=1;
		if(s2[2]=='C')s=1;
	}
	if(s1[2]=='B'){
		if(s2[2]=='A')s=1;
		if(s2[2]=='C')s=1;
	}
	if(s1[2]=='C'){
		if(s2[2]=='B')s=1;
		if(s2[2]=='A')s=1;
	}
	if(s1[2]=='D'){
		if(s2[2]=='F')s=1;
	}
	if(s1[2]=='F'){
		if(s2[2]=='D')s=1;
	}
	cout<<s;
	s=0;
	if(s1[2]=='A'){
		if(s2[2]=='B')s=1;
	}
	if(s1[2]=='B'){
		if(s2[2]=='A')s=1;
		if(s2[2]=='C')s=1;
	}
	if(s1[2]=='C'){
		if(s2[2]=='B')s=1;
	}
	if(s1[2]=='D'){
		if(s2[2]=='F')s=1;
	}
	if(s1[2]=='F'){
		if(s2[2]=='D')s=1;
	}
	cout<<s;
	return 0;
}
