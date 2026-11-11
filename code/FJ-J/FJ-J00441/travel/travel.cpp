#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("trave.out","w",stdout);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	bool o=false,t=false,e=false;
	if(cc==c){
		cout<<"1";
		o=true;
	}
	else{
		cout<<"0";
	}
	if(o&&s[0]==ss[0]&&s[1]==ss[1]){
		cout<<"1";
		t=true;
	}
	else{
		cout<<"0";
	}
	if(t){
		if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(ss[2]=='A'||ss[2]=='B'||ss[2]=='C')){
			e=true;
			cout<<"1";
		}
		else if((s[2]=='F'||s[2]=='D')&&(ss[2]=='D'||ss[2]=='F')){
			e=true;
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"0";
	}
	if(e){
		if(s[2]=='A'&&ss[2]=='B'){
			cout<<"1";
		}
		else if(s[2]=='B'&&(ss[2]=='A'||ss[2]=='C')){
			cout<<"1";
		}
		else if(s[2]=='C'&&ss[2]=='B'){
			cout<<"1";
		}
		else if((s[2]=='F'||s[2]=='D')&&(ss[2]=='F'||ss[2]=='D')){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"0";
	}
	return 0;
} 
