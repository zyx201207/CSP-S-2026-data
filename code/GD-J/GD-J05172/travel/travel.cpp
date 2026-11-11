#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	string as,bs;
	cin>>a>>as>>b>>bs;
	cout<<(a==b?1:0);
	if(a!=b){
		cout<<0<<0<<0;
		return 0;
	}
	int ass=((as[0]-'0')*10+(as[1]-'0'));
	int bss=((bs[0]-'0')*10+(bs[1]-'0'));
	cout<<(ass==bss?1:0);
	if(ass!=bss){
		cout<<0<<0;
		return 0;
	}
	if(as[2]=='A'||as[2]=='B'||as[2]=='C'){
		if(bs[2]=='A'||bs[2]=='B'||bs[2]=='C') cout<<1;
		else cout<<0;
	}else{
		if(bs[2]=='D'||bs[2]=='F') cout<<1;
		else cout<<0;
	}
	if(as[2]=='A'){
		if(bs[2]=='B') cout<<1;
		else cout<<0;
	}
	if(as[2]=='B'){
		if(bs[2]=='A'||bs[2]=='C') cout<<1;
		else cout<<0;
	}
	if(as[2]=='C'){
		if(bs[2]=='B') cout<<1;
		else cout<<0;
	}
	if(as[2]=='D'){
		if(bs[2]=='F') cout<<1;
		else cout<<0;
	}
	if(as[2]=='F'){
		if(bs[2]=='D') cout<<1;
		else cout<<0;
	}
	return 0;
}
