#include<bits/stdc++.h>
using namespace std;
string s,x,ds,dx;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	cin>>s>>x>>ds>>dx;
	if(s[0]==dx[0]&&s[1]==ds[1])cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(x[0]==dx[0]&&x[1]==dx[1])cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if(x[2]=='A'||x[2]=='B'||x[2]=='C'){
		if(dx[2]=='A'||dx[2]=='B'||dx[2]=='C'){
			cout<<1;
		}
		else {
			cout<<"00";
			return 0;
		}
	}
	else if(x[2]=='D'||x[2]=='F'){
		if(dx[2]=='D'||dx[2]=='F'){
			cout<<1;
		}
		else {
			cout<<"00";
			return 0;
		}
	}
	if(x[2]=='A'){
		if(dx[2]=='B')cout<<1;
		else {
			cout<<0;
			return 0;
		}
	}
	else if(x[2]=='B'){
		if(dx[2]=='A'||dx[2]=='C')cout<<1;
		else {
			cout<<0;
			return 0;
		}
	}
	else if(x[2]=='C'){
		if(dx[2]=='B')cout<<1;
		else {
			cout<<0;
			return 0;
		}
	}
	else if(x[2]=='D'){
		if(dx[2]=='F')cout<<1;
		else {
			cout<<0;
			return 0;
		}
	}
	else if(x[2]=='F'){
		if(dx[2]=='D')cout<<1;
		else {
			cout<<0;
			return 0;
		}
	}
   
	return 0;
} 
