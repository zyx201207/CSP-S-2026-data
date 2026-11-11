#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<"1";
		if(s[0]==ss[0] && s[1]==ss[1]){
			cout<<"1";
			if(s[2]=='A'){
				if(ss[2]=='B'){cout<<"11";}
				else if(ss[2]=='C'){cout<<"10";}
				else{cout<<"00";}
			}
			if(s[2]=='B'){
				if(ss[2]=='A' || ss[2]=='C'){cout<<"11";}
				else{cout<<"00";}
			}
			if(s[2]=='C'){
				if(ss[2]=='B'){cout<<"11";}
				else if(ss[2]=='A'){cout<<"10";}
				else{cout<<"00";}
			}
			if(s[2]=='D'){
				if(ss[2]=='F'){cout<<"11";}
				else{cout<<"00";}
			}
			if(s[2]=='F'){
				if(ss[2]=='D'){cout<<"11";}
				else{cout<<"00";}
			}
		}
		else{cout<<"000";}
	}
	else{cout<<"0000";}
	return 0;
}
