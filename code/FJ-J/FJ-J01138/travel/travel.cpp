#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1[0]==b1[0]){
		if(a1[1]==b1[1]){
			cout<<1;
			if(a2[0]==b2[0]){
				if(a2[1]==b2[1]){
					cout<<1;
					if(a2[2]=='A'&&b2[2]=='B'||b2[2]=='A'&&a2[2]=='B'){
						cout<<"11";
						return 0;
					}
					if(a2[2]=='D'&&b2[2]=='F'||b2[2]=='D'&&a2[2]=='F'){
						cout<<"11";
						return 0;
					}
					if(a2[2]=='B'&&b2[2]=='C'||b2[2]=='B'&&a2[2]=='C'){
						cout<<"11";
						return 0;
					}
					if(a2[2]=='A'&&b2[2]=='C'||b2[2]=='A'&&a2[2]=='C'){
						cout<<"10";
						return 0;
					}
					cout<<"00";
					return 0;
				}
				cout<<"000";
				return 0;
			}
			cout<<"000";
			return 0;
		}
		cout<<"0000";
		return 0;
	} 
	cout<<"0000";
	return 0;
} 
