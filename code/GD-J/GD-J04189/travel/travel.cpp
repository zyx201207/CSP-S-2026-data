#include<bits/stdc++.h>
using namespace std;
int c,cc;
string s,ss;
int a,b;
bool f=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	a=(s[0]-'0')*10+s[1]-'0',b=(ss[0]-'0')*10+ss[1]-'0';
	if(a==b){
		cout<<"1";
		if((s[2]=='D'||s[2]=='F')&&(ss[2]=='D'||ss[2]=='F')){
			cout<<"1";
			f=1;
		}
		else if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(ss[2]=='A'||ss[2]=='B'||ss[2]=='C')){
			cout<<"1";
			f=1;
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"00";
	}
	if(f==1){
		if(abs((s[2]-'A')-(ss[2]-'A'))==1||(s[2]==ss[2]&&abs(a-b)==1)){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else cout<<"0";
	return 0;
} 
