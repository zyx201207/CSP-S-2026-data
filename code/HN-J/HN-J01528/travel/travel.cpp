#include<bits/stdc++.h>
using namespace std;
int a1,b1;
char a2[5],b2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1;
	for(int i=1;i<=3;i++){
		cin>>a2[i];
	}
	cin>>b1;
	for(int i=1;i<=3;i++){
		cin>>b2[i];
	}
	if(a1==b1){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a2[1]==b2[1]&&a2[2]==b2[2]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(a2[3]=='D'&&b2[3]=='A'){
		cout<<"00";
	}
	if(a2[3]=='D'&&b2[3]=='B'){
		cout<<"00";
	}
	if(a2[3]=='D'&&b2[3]=='C'){
		cout<<"00";
	}
	if(a2[3]=='F'&&b2[3]=='A'){
		cout<<"00";
	}if(a2[3]=='F'&&b2[3]=='B'){
		cout<<"00";
	}if(a2[3]=='F'&&b2[3]=='C'){
		cout<<"00";
	}
	if(a2[3]=='D'&&b2[3]=='F'){
		cout<<11;
	}
	if(a2[3]=='F'&&b2[3]=='D'){
		cout<<11;
	}
	else if(a2[3]=='A'){
		if(b2[3]=='B'){
			cout<<11;
		}
		if(b2[3]=='C'){
			cout<<10;
		}
		if(b2[3]=='D'){
			cout<<"00";
		}
		if(b2[3]=='F'){
			cout<<"00";
		}
	}
	else if(a2[3]=='B'){
		if(b2[3]=='A'){
			cout<<11;
		}
		if(b2[3]=='C'){
			cout<<11;
		}
		if(b2[3]=='D'){
			cout<<"00";
		}
		if(b2[3]=='F'){
			cout<<"00";
		}
	}	
	else if(a2[3]=='C'){
		if(b2[3]=='B'){
			cout<<11;
		}
		if(b2[3]=='A'){
			cout<<10;
		}
		if(b2[3]=='D'){
			cout<<"00";
		}
		if(b2[3]=='F'){
			cout<<"00";
		}
	}
return 0;}
