#include<bits/stdc++.h>
using namespace std;
string s,s1,ss,ss1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>ss>>ss1;
	if(s==ss){
		cout<<"1";
		if(s1[0]==ss1[0]&&s1[1]==ss1[1]){
			cout<<"1";
			if((s1[2]=='D'&&ss1[2]=='F')||(ss1[2]=='D'&&s1[2]=='F')){
				cout<<"11";
			}else if(s1[2]=='A'&&ss1[2]=='C'){
				cout<<"10";
			}else if(s1[2]=='B'&&ss1[2]=='C'){
				cout<<"11";
			}else if(s1[2]=='A'&&ss1[2]=='B'){
				cout<<"11";
			}else if(s1[2]=='C'&&ss1[2]=='B'){
				cout<<"10";
			}else if(s1[2]=='B'&&ss1[2]=='A'){
				cout<<"11";
			}else if(s1[2]=='C'&&ss1[2]=='A'){
				cout<<"10";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
