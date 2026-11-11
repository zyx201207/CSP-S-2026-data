#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char e,f; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>e;
	c+=(e-'0')*10;
	cin>>e;
	c+=e-'0';
	cin>>e>>b>>f;
	d+=(f-'0')*10;
	cin>>f;
	d+=f-'0';
	cin>>f;
	if(a==b) cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	if(d==c) cout<<'1';
	else cout<<'0';
	if(d==c){
		if(e<='C'&&f<='C'||e>'C'&&f>'C') cout<<'1';
	else cout<<'0';
	}
	else cout<<'0';
	if(d==c){
		if(e=='C'&&f=='D') cout<<'0';
		else{
			if(e-f==1||e-f==-1) cout<<'1';
		else cout<<'0';
		}
	}
	else cout<<'0';
	return 0;
}
