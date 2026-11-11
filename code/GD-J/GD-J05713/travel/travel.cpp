#include<bits/stdc++.h>
using namespace std;
string n,a,m,b,aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n==m){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	aa+=a[0]+a[1];
	bb+=b[0]+b[1];
	if(aa==bb){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a[2]>='A'&&a[2]<='C'&&b[2]>='A'&&b[2]<='C'&&aa==bb){
		cout<<1;
	}
	else if(a[2]>='D'&&a[2]<='F'&&b[2]>='D'&&b[2]<='F'&&aa==bb){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(aa==bb){
		if(a[2]=='A'&&b[2]=='B'){
			cout<<1;
		}
		else if(a[2]=='B'&&b[2]=='C'){
			cout<<1;
		}
		else if(a[2]=='B'&&b[2]=='A'){
			cout<<1;
		}
		else if(a[2]=='C'&&b[2]=='B'){
			cout<<1;
		}
		else if(a[2]=='D'&&b[2]=='F'){
			cout<<1;
		}
		else if(a[2]=='F'&&b[2]=='D'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;
} 
