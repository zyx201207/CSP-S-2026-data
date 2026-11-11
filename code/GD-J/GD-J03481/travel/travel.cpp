#include <bits/stdc++.h>
using namespace std;
string c[2],s[2];
int main(){
	for(int i=0;i<2;i++){
		cin>>c[i];
	}
	for(int i=0;i<2;i++){
		cin>>s[i];
	}
	if(c[0][0]==s[0][0]&&c[0][1]==s[0][1]){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(c[1][0]==s[1][0]&&c[1][1]==s[1][1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(c[1][2]=='A'||c[1][2]=='B'||c[1][2]=='C'){
		if(s[1][2]=='D'||s[1][2]=='F'){
			cout<<"00";
			return 0;
		}else{
			cout<<"1";
		}
	}else{
		if(s[1][2]=='A'||s[1][2]=='B'||s[1][2]=='C'){
			cout<<"00";
			return 0;
		}else{
			cout<<"1";
		}
	}
	if(c[1][2]=='A'){
		if(s[1][2]=='B'){
			cout<<"1";
		}
	}else if(c[1][2]=='B'){
		if(s[1][2]=='A'||s[1][2]=='C'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else if(c[1][2]=='C'){
		if(s[1][2]=='B'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else if(c[1][2]=='D'){
		if(s[1][2]=='F'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		if(s[1][2]=='D'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
} 
