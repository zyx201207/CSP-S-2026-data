#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	if(c!=cc){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	
	if(s[0]==ss[0]&&s[1]==ss[1]){
		cout<<"1";
	}
	else{
	 cout<<"000";
	 return 0;
	}
	if(s[2]=='A'||s[2]=='B'||s[2]=='C'){
		if(ss[2]=='A'||ss[2]=='B'||ss[2]=='C'){
			cout<<"1";
			if((s[2]=='A'&&ss[2]=='B')||(s[2]=='B'&&ss[2]=='C')){
				cout<<"1";
			}
			else{
			 	cout<<"0";
			}
		}
		else {
			cout<<"00";
			return 0;
		}
	}
		
	else if(s[2]=='D'||s[2]=='F'){
		 if(ss[2]=='D'||ss[2]=='F'){
			cout<<"11";
			return 0;
		}
		else {
			cout<<"00";
			return 0;
		}
	}
	return 0;
}
