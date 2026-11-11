#include<bits/stdc++.h>
using namespace std;
int a[10];
string b;
string c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[1]>>b;
	cin>>a[2]>>c;
	if(a[1]==a[2]) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(b[0]==c[0]){
		if(b[1]==c[1]){
			cout<<1;
		}
		else{
			cout<<0<<0<<0;
			return 0;
		}
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(b[2]=='A'){
		if(c[2]=='B') cout<<11;
		else if(c[2]=='C') cout<<10;
		else cout<<0<<0;
	}
	else if(b[2]=='B'){
		if(c[2]=='A' || c[2]=='C') cout<<11;
		else cout<<0<<0;
	}
	else if(b[2]=='C'){
		if(c[2]=='B') cout<<11;
		else if(c[2]=='A') cout<<10;
		else cout<<0<<0;
	}
	else if(b[2]=='D'){
		if(c[2]=='F') cout<<11;
		else cout<<0<<0;
	}
	else if(b[2]=='F'){
		if(c[2]=='F') cout<<11;
		else cout<<0<<0;
	}
	return 0;
} 
