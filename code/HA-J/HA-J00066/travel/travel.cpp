#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool f1=1,f2=1,f3=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
		f1=1;	
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	
	string s5=s2.substr(0,2),s6=s4.substr(0,2);
	if(s5==s6){
		cout<<1;
		f2=1;
	}
	else{
		cout<<"000";
		return 0;
	}
	char c1=s2[2],c2=s4[2];
	
	
	if(c1=='A'){
		if(c2=='B' || c2=='C'){
			cout<<1;
			f3=1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(c1=='B'){
		if((c2=='A' || c2=='C')) {
			cout<<1;
			f3=1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(c1=='C'){
		if((c2=='A' || c2=='B')){
			cout<<1;
			f3=1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(c1=='D'){
		if((c2=='F')){
			cout<<1;
			f3=1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(c1=='F'){
		if((c2=='D')){
			cout<<1;
			f3=1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	
	
	if(c1=='A'){
		if(c2=='B'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(c1=='B'){
		if((c2=='A' || c2=='C')){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(c1=='C'){
		if((c2=='B')){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(c1=='D'){
		if(c2=='F'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(c1=='F'){
		if(c2=='D'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
