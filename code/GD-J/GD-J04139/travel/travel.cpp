#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cf,sf,cs,ss;
	cin>>cf>>sf>>cs>>ss;
	if(cf==cs){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(sf[0]==ss[0]&&sf[1]==ss[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((sf[2]=='D'&&ss[2]=='F')||(sf[2]=='F'&&ss[2]=='D')){
		cout<<1;
		cout<<1;
	}
	else if((sf[2]=='A'&&ss[2]=='B')||(sf[2]=='B'&&ss[2]=='A')){
		cout<<1<<1;
	}
	else if((sf[2]=='B'&&ss[2]=='C')||(sf[2]=='C'&&ss[2]=='B')){
		cout<<1<<1;
	}
	else if((sf[2]=='A'&&ss[2]=='C')||(sf[2]=='C'&&ss[2]=='A')){
		cout<<1<<0;
	}
	else{
		cout<<0<<0;
	}
	return 0;
}
