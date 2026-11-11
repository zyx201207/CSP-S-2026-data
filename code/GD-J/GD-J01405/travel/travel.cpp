#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else if(s1[1]!=s2[1] or s1[0]!=s2[0]){
		cout<<"1000";
	}else{
		char c=s1[2],x=s2[2];
		cout<<"11";
		if(c=='A' and (x=='B' or x=='C')){
			cout<<"1";
			if(c=='A' and x=='B'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if(c=='B' and (x=='A' or x=='C')){
			cout<<"1";
			if((c=='B' and x=='C') or (c=='B' and x=='A')){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if(c=='C' and (x=='A' or x=='B')){
			cout<<"1";
			if(c=='C' and x=='B'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if((c=='D' and x=='F') or (c=='F' and x=='D')){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}
	return 0;
} 
