#include<bits/stdc++.h>
using namespace std;
char a2,b2,t,a3,b3;
int a,b,a1,b1;
int main(){
	freopen("travel.in","r",stdin); 
    freopen("travel.out","w",stdout);
	 
	cin>>t;
	if(t!='0') a=10;
	cin>>t;
	a+=t-'0';
	cin>>t;
	if(t!='0') a2=10;
	cin>>t;
	a2+=t-'0';
	cin>>a3;
	
	cin>>t;
	if(t!='0') b=10;
	cin>>t;
	b+=t-'0';
	cin>>t;
	if(t!='0') b2=10;
	cin>>t;
	b2+=t-'0';
	cin>>b3;
	
	if(a!=b) cout<<"0000";
	else if(a2!=b2) cout<<1000;
 	else if(a3=='F'&&b3=='D' || a3=='D'&&b3=='F') {
	 cout<<111;
	 if(a3-b3==1||b3-a3==1) cout<<1;
	 else cout<<0;}
 	else if(a3!='F'&&b3!='F'&&b3!='D'&&a3!='D') {
	 cout<<111;
	 if(a3-b3==1||b3-a3==1) cout<<1;
	 else cout<<0;}
	 else cout<<1100;
	return 0;
}

