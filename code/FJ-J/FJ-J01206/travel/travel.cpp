#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1.substr(0,2)==s2.substr(0,2)){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	char r=s1[2],x=s2[2];
	if(r=='F'||r=='D'){
		if(x=='F'||x=='D'){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}else{
		if(x=='F'||x=='D'){
			cout<<"00";
		}else{
			cout<<"1";
			if(r=='B'){
				cout<<"1";
			}else{
				if(x=='B'){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}
	}
	return 0;
} 
