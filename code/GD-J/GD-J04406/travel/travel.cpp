#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	string s="",ss="";
	for(int i=0;i<=1;i++){
		s+=s1[i];
		ss+=s2[i];
	}
	char h,hh;
	h=s1[2],hh=s2[2];
	if(c1==c2 and s==ss){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c1==c2 and s==ss){
		if(h=='A'||h=='B'||h=='C'){
			if(hh=='A'||hh=='B'||hh=='C'){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
		else if(h=='D'||h=='F'){
			if(h=='D'||h=='F'){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
	}
	else{
		cout<<"0";
	}
	if(c1==c2 and s==ss){
		if(h=='A' and hh=='B'){
			cout<<"1";
		}
		else if(h=='B' and (hh=='A'||hh=='C')){
			cout<<"1";
		}
		else if(h=='C' and hh=='B'){
			cout<<"1";
		}
		else if(h=='D' and hh=='E'){
			cout<<"1";
		}
		else if(h=='E' and hh=='D'){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"0";
	}
}
