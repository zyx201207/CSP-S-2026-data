#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s,t;
	cin>>a>>s>>b>>t;
	if(a==b){
		cout<<1;
		if(s[0]+s[1]==t[0]+t[1]){
			cout<<1;
			if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(t[2]=='A'||t[2]=='B'||t[2]=='C')||(s[2]=='D'||s[2]=='F')&&(t[2]=='D'||t[2]=='F')){
				cout<<1;
				if(s[2]=='A'&&t[2]=='B'||s[2]=='B'&&t[2]=='A'||s[2]=='B'&&t[2]=='C'||s[2]=='C'&&t[2]=='B'||s[2]=='D'&&t[2]=='F'||s[2]=='F'&&t[2]=='D'){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
}
