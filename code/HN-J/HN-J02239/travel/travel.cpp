#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4; 
	if(s1==s3){
		cout<<"1";
	}
	else cout<<"0";
	if(s2[0]==s4[0] && s2[1]==s4[1]){
		cout<<"1";
	}
	else cout<<"0";
	if(s2[0]==s4[0] && s2[1]==s4[1]){
		if(s2[2]=='A'){
			if(s4[2]=='B' || s4[2]=='C'){
				cout<<"1";
			}
			else cout<<"0";
		}
		else if(s2[2]=='B'){
			if(s4[2]=='A' || s4[2]=='C'){
				cout<<"1";
			}
			else cout<<"0";
		}
		else if(s2[2]=='C'){
			if(s4[2]=='A' || s4[2]=='B'){
				cout<<"1";
			}
			else cout<<"0";
		}
		else if(s2[2]=='D'){
			if(s4[2]=='E'){
				cout<<"1";
			}
			else cout<<"0";
		}
		else if(s2[2]=='E'){
			if(s4[2]=='D'){
				cout<<"1";
			}
			else cout<<"0";
		}
	}
	else cout<<"0";
	if(s2[0]==s4[0] && s2[1]==s4[1]){
		if(s2[2]=='A'){
			if(s4[2]=='B'){
				cout<<"1";
			}
	    else cout<<"0";
		}
		else if(s2[2]=='B'){
			if(s4[2]=='A' || s4[2]=='C'){
				cout<<"1";
			}
			else cout<<"0";
		}
		else if(s2[2]=='C'){
			if(s4[2]=='B'){
				cout<<"1";
			}
			else cout<<"0";
		}
		else if(s2[2]=='D'){
			if(s4[2]=='E'){
				cout<<"1";
			}
			else cout<<"0";
		}
		else if(s2[2]=='E'){
			if(s4[2]=='D'){
				cout<<"1";
			}
			else cout<<"0";
		}
	}
	else cout<<"0";
	return 0;
} 
