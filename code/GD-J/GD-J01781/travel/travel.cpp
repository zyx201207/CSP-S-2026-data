#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	string c,s;
	c=s1[0];    c+=s1[1];
	s=s2[0];    s+=s2[1];
	if(c==s){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	char a=s1[2],b=s2[2];
	if(a=='D'||a=='F'){
		if(b=='D'||b=='F'){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else{
		if(b=='A'||b=='B'||b=='C'){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(a=='D'||a=='F'){
		cout<<1;
	}
	else{
		if(b=='A'&&a=='B'||b=='B'&&a=='C'||a=='A'&&b=='B'||a=='B'&&b=='C'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
} 
