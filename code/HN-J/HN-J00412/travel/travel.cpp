#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string c,c2,s,s2;
string u,v;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>s>>c2>>s2;
	if(c==c2){
		cout<<1;
		u=s[0];
		u+=s[1];
		v=s2[0];
		v+=s2[1];
		if(v==u){
			cout<<1;
			if(s[2]=='A'&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				cout<<1;
			}else if(s[2]=='B'&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				cout<<1;
			}else if(s[2]=='C'&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				cout<<1;
			}else if(s[2]=='D'&&(s2[2]=='D'||s2[2]=='F')){
				cout<<1;
			}else if(s[2]=='F'&&(s2[2]=='D'||s2[2]=='F')){
				cout<<1;
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	if(s[2]<='C'){
		if(s[2]=='A'&&s2[2]=='B'){
			cout<<1;
		}else if(s[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
			cout<<1;
		}else if(s[2]=='C'&&s2[2]=='B'){
			cout<<1;
		}else{
			cout<<0;
			return 0;
		}
	}else{
		if(s[2]=='D'&&s2[2]=='F'){
			cout<<1;
		}else if(s[2]=='F'&&s2[2]=='D'){
			cout<<1;
		}else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
