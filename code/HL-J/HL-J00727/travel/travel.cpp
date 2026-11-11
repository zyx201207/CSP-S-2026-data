#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,a1=0,a2=0,a3=0;
	string c,d;
	cin>>a;cin>>c;cin>>b;cin>>d;
	if(a==b){
		cout<<"1";
	}
	else {
	cout<<"0";
	a1=1;
	}
	if(c[0]==d[0]&&c[1]==d[1]&&a1!=1){
		cout<<"1";
	}
	else {
		cout<<0;a2=1;
	}
	if(c[2]<='C'&&c[2]>='A'&&d[2]<='C'&&d[2]>='A'&&a2!=1){
		cout<<"1";
	}
	else if((c[2]=='D'||c[2]=='F')&&(d[2]=='D'||d[2]>='F')&&a2!=1){
		cout<<"1";
	} 
	else {
		cout<<"0";
		a3=1;
	}
	if(c[2]=='F'&&a3!=1){
		cout<<"1";
	}
	else if(c[2]=='B'||d[2]=='B'){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}