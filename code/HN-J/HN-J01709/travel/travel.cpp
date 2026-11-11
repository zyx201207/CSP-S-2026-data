#include<bits/stdc++.h>
using namespace std;
int c1,c2,h1,h2,ce1,ce2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	h1=(s1[0]-'0')*10+(s1[1]-'0'),h2=(s2[0]-'0')*10+(s2[1]-'0');
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		ce1=1; 
	}
	else{
		ce1=2; 
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		ce2=1; 
	}
	else{
		ce2=2; 
	}
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c2&&h1==h2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c2&&ce1==ce2&&h1==h2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(ce1==ce2&&h1==h2&&c1==c2){
		if(ce1==2){
			cout<<1;
		}
		else{
			if(abs(s1[2]-s2[2])==1){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
	}
	else{
		cout<<0;
	}
	return 0;
}
