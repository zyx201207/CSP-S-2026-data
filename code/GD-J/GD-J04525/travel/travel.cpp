#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		char c1=s2[0];
		char c2=s2[1];
		char c3=s4[0];
		char c4=s4[1];
		if(c1!=c3||c2!=c4){
			cout<<"000";
			return 0;
		}
		else{
			cout<<"1";
			char c5=s2[2];
			char c6=s4[2];
			if((c5=='A'&&c6=='B')||(c5=='B'&&c6=='A')||(c5=='C'&&c6=='B')||(c5=='B'&&c6=='C')||(c5=='D'&&c6=='F')||c5=='F'&&c6=='D'){
				cout<<"11";
				return 0;
			}
			else{
				if((c5=='A'&&c6=='C')||(c5=='C'&&c6=='A')){
					cout<<"10";
					return 0;
				}
				else{
					cout<<"00";
					return 0;
				}
			}
		}
	}
	return 0;
} 
