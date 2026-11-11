#include<bits/stdc++.h>
using namespace std;
string c,s,c_,s_;
int a=0,b=0,d=0,e=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c_>>s_;
	if(c==c_){
	a=1;
	b=1;
	for(int i=0;i<=1;i++){
		if(s[i]!=s_[i])b=0;
	}
}
	if(b==1){
		if(s[2]=='A'||s[2]=='B'||s[2]=='C'){
		if(s_[2]=='A'||s_[2]=='B'||s_[2]=='C'){
		d=1;
		if(s[2]=='A'&&s_[2]=='B')e=1;
		else if(s[2]=='B'&&s_[2]=='C')e=1;
	}
	}
	else if(s[2]=='D'||s[2]=='F'){
		if(s_[2]=='D'||s_[2]=='F'){
			d=1;
			e=1;
		}
	}
	}
	cout<<a<<b<<d<<e;
	return 0;
}
