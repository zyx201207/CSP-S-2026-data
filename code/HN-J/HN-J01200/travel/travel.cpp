#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a;
	cin>>a;
	string a2;
	cin>> a2;
	int b;
	cin>>b;
	string b2;
	cin>>b2;
		if(a==b){
		cout<<1;
	}else{
		cout<<"0000";
	}
	if(a==b){
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;
}else{
	cout<<"000";
}
}
if(a==b){
if(a2[0]==b2[0]&&a2[1]==b2[1]){
	if(a2[2]=='A'){
		if(b2[2]=='B'||b2[2]=='C'){
			cout<<1;
		}
		if(b2[2]=='D'||b2[2]=='E'){
			cout<<0;
		}
		if(b2[2]=='B'){
			cout<<1;
		}
		if(b2[2]=='C'||b2[2]=='D'||b2[2]=='E'){
			cout<<0;
		}
	}
	
		if(a2[2]=='B'){
		if(b2[2]=='A'||b2[2]=='C'){
			cout<<1;
			cout<<1;
		}
		if(b2[2]=='D'||b2[2]=='E'){
			cout<<0;
			cout<<0;
		}
	}
	
		if(a2[2]=='C'){
		if(b2[2]=='B'||b2[2]=='A'){
			cout<<1;
		}
		if(b2[2]=='D'||b2[2]=='E'){
			cout<<0;
			cout<<0;
		}
		if(b2[2]=='B'){
			cout<<1;
		}
		if(b2[2]=='A'){
			cout<<0;
		}
	}
	
		if(a2[2]=='D'){
		if(b2[2]=='B'||b2[2]=='C'||b2[2]=='A'){
			cout<<0;
			cout<<0;
		}
		if(b2[2]=='E'){
			cout<<1;
			cout<<1;
		}
	}
		if(a2[2]=='E'){
		if(b2[2]=='B'||b2[2]=='C'||b2[2]=='A'){
			cout<<0;
			cout<<0;
		}
		if(b2[2]=='D'){
			cout<<1;
			cout<<1;
		}
	}
}
}
	return 0;
} 
