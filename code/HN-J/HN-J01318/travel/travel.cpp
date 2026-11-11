#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b,c,d,e,f,g,h,i,j;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
	if(a==f&&b==g){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	if(c==h&&d==i){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
		
	if(e=='A'&&j=='B'){
		cout<<1;
	}
	else if(e=='B'&&j=='A'){
		cout<<1;
	}
	else if(e=='A'&&j=='C'){
		cout<<1;
	}
	else if(e=='C'&&j=='A'){
		cout<<1;
	}
	else if(e=='B'&&j=='C'){
		cout<<1;
	}
	else if(e=='C'&&j=='B'){
		cout<<1;
	}
	else if(e=='D'&&j=='F'){
		cout<<1;
	}
	else if(e=='F'&&j=='D'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	if(e=='A'&&j=='B'){
		cout<<1;
	}
	else if(e=='B'&&j=='A'){
		cout<<1;
	}
	else if(e=='B'&&j=='C'){
		cout<<1;
	}
	else if(e=='C'&&j=='B'){
		cout<<1;
	}
	else if(e=='D'&&j=='F'){
		cout<<1;
	}
	else if(e=='F'&&j=='D'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
