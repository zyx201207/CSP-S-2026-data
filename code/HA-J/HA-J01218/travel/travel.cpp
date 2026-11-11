#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	int q=1;
	if(b[1]==d[1] and b[0]==d[0]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((b[2]=='A' or b[2]=='B' or b[2]=='C') and 
	(d[2]=='A' or d[2]=='B' or d[2]=='C')){
		cout<<"1";
		q=0;
	}
	if((b[2]=='D' or b[2]=='F') and 
	(d[2]=='D' or d[2]=='F')){
		cout<<"11";
		return 0;
		q=0;
	}
	if(q==1){
		cout<<"00";
		return 0;
	}
	if(b[2]=='A'){
		if(d[2]=='B'){
			cout<<"1";
			return 0;
		}
		cout<<"0";
		return 0;
	}
	if(b[2]=='B'){
		cout<<"1";
		return 0;
	}
	if(b[2]=='C'){
		if(d[2]=='B'){
			cout<<"1";
			return 0;
		}
		cout<<"0";
		return 0;
	}
	
	return 0;
}