#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","o",stdout);
	cin>>a>>b>>e>>d>>c>>f;
	if(a==d){
		cout<<1;
		if(b==c){
			cout<<1;
			if('A'<=f&&f<='C'&&'A'<=e&&e<='C'&&f!=e) cout<<1;
	else if('D'<=f&&f<='F'&&'D'<=e&&e<='F'&&f!=e) cout<<1;
	else cout<<0;
		}else cout<<0<<0;
	if('D'<=f&&f<='F'&&'D'<=e&&e<='F'||f=='A'&&e=='B'||f=='B'&&e=='A'||f=='B'&&e=='C'||f=='C'&&e=='B'){
		if(b==c){
			cout<<1;
		}else cout<<0;
	}else cout<<0;
	}else cout<<0<<0<<0<<0;
		
	return 0;
} 
