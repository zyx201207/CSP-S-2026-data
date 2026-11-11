#include<bits/stdc++.h>
using namespace std;
int s1,c1,y,x;
string s2,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>c1>>c2;
	if(s1==c1)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s2[1]==c2[1])cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s2[2]=='C'||s2[2]=='B'||s2[2]=='A')y=1;
	else y=2;
	if(c2[2]=='C'||c2[2]=='B'||c2[2]=='A')x=1;
	else x=2;
	if(x==y)cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(s2[2]=='A'&&c2[2]=='B'){
		cout<<1;
		return 0;
	}
	if(s2[2]=='B'&&c2[2]=='A'){
		cout<<1;
		return 0;
	}
	if(s2[2]=='C'&&c2[2]=='B'){
		cout<<1;
		return 0;
	}
	if(s2[2]=='B'&&c2[2]=='C'){
		cout<<1;
		return 0;
	}
	if(s2[2]=='D'&&c2[2]=='F'){
		cout<<1;
		return 0;
	}
	if(s2[2]=='F'&&c2[2]=='D'){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
