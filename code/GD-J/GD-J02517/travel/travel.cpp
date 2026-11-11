#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a2,b,b2;
	cin>>a>>a2>>b>>b2;
	if(a==b){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a2[1]==b2[1]&&a2[0]==b2[0]){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	if('A'<=a2[2]&&'C'>=a2[2]){
		if('A'<=b2[2]&&'C'>=b2[2]){
			cout<<'1';
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else if('D'<=a2[2]&&'F'>=a2[2]){
		if('D'<=b2[2]&&'F'>=b2[2]){
			cout<<'1';
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(int(a2[2])-int(b2[2])==1||int(b2[2])-int(a2[2])==1){
		cout<<'1';
	}
	else if(a2[2]=='F'&&b2[2]=='D'||b2[2]=='F'&&a2[2]=='D'){
		cout<<'1';
	} 
	else{
		cout<<'0';
	}
	return 0;
} 
