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
		cout<<0<<0<<0<<0;
		return 0;
	}
	char chx,chr;
	chx=s1[s1.size()-1];
	chr=s2[s2.size()-1];
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((chx=='A'&&chr=='B')||(chx=='A'&&chr=='C')||(chx=='B'&&chr=='A')||(chx=='B'&&chr=='C')||(chx=='C'&&chr=='A')||chx=='C'&&chr=='B'){
		cout<<1;
	}
	else if((chx=='F'&&chr=='D')||(chx=='D'&&chr=='F')){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(chx+1==chr||chx==chr+1){
		if((chx=='C'&&chr=='D')||(chx=='D'&&chr=='C')){
			cout<<0;
		} 
		else{
			cout<<1;
		}
	}
	else{
		cout<<0;
	}
	return 0;
} 
