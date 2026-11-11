#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a>>c2>>b;
	if(c1==c2){
		cout<<"1";
	}else {
		cout<<"0"<<"0"<<"0"<<"0";
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<"1";
	}else {
		cout<<"0"<<"0"<<"0";
		return 0;
	}
	if(a[2]=='A'){
		if(b[2]=='B'){
			cout<<"1"<<"1";
		}
		else if(b[2]=='C'){
			cout<<"1"<<"0";
		}else{
			cout<<"0"<<"0";
		}
	}
	if(a[2]=='B'){
		if(b[2]=='A'){
			cout<<"1"<<"1";
		}
		else if(b[2]=='C'){
			cout<<"1"<<"1";
		}else{
			cout<<"0"<<"0";
		}
	}
	if(a[2]=='C'){
		if(b[2]=='B'){
			cout<<"1"<<"1";
		}
		else if(b[2]=='A'){
			cout<<"1"<<"0";
		}else{
			cout<<"0"<<"0";
		}
	}
	if(a[2]=='D'){
		if(b[2]=='F'){
			cout<<"1"<<"1";
		}else{
			cout<<"0"<<"0";
		}
	}
	if(a[2]=='F'){
		if(b[2]=='D'){
			cout<<"1"<<"1";
		}else{
			cout<<"0"<<"0";
		}
	}
	return 0;
}
