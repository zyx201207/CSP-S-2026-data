#include<bits/stdc++.h>
using namespace std;
int q(string s){
	if(s[2]=='A'||s[2]=='B'||s[2]=='C') return 1;
	else return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1) cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	if(r2.substr(0,2)==x2.substr(0,2)) cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	if(q(r2)==q(x2)) cout<<'1';
	else{
		cout<<"00";
		return 0;
	}
	if(r2[2]=='A'&&x2[2]=='C' || r2[2]=='C'&&x2[2]=='A') cout<<'0';
	else cout<<'1';
	return 0;
}
