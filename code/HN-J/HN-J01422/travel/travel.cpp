#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,a,b;
	cin>>a>>s>>b>>s1;
	if(a==b){
		cout<<"1";
			if(s[0]==s1[0]&&s[1]==s1[1]){
		cout<<"1";
		if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(s1[2]=='D'||s1[2]=='F')){
			cout<<"00";
		}else if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s[2]=='D'||s[2]=='F')){
			cout<<"00";
		}else{
			cout<<"1";
			if((s[2]=='A'&&s1[2]=='C')||(s1[2]=='A'&&s[2]=='C')){
				cout<<"0";
			}else{
				cout<<"1";
			}
		}
	}else{
		cout<<"000";
	}
	}else{
		cout<<"0000";
	}

	return 0;
} 
