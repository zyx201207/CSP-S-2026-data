#include<bits/stdc++.h>
using namespace std;
long long n,c[2];
string s[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c[0]>>s[0]>>c[1]>>s[1];
	if(c[0]!=c[1]){
		cout<<"0000";
		return 0;
	}
	if(s[0][0]!=s[1][0]||s[0][1]!=s[1][1]){
		cout<<"1000";
		return 0;
	}
	if(s[0][2]<'D'&&s[1][2]>'C'){
		cout<<"1100";
		return 0;
	}
	if(s[1][2]<'D'&&s[0][2]>'C'){
		cout<<"1100";
		return 0;
	}
	if(s[1][2]=='D'&&s[0][2]!='F'){
		cout<<"1110";
		return 0;
	}
	if(s[0][2]=='D'&&s[1][2]!='F'){
		cout<<"1110";
		return 0;
	}
	if(s[1][2]=='B'&&(s[0][2]=='F'||s[0][2]=='D')){
		cout<<"1110";
		return 0;
	}
	if(s[0][2]=='B'&&(s[1][2]=='F'||s[1][2]=='D')){
		cout<<"1110";
		return 0;
	}
	if(s[0][2]=='A'&&s[1][2]!='B'){
		cout<<"1110";
		return 0;
	}
	if(s[0][2]=='C'&&s[1][2]!='B'){
		cout<<"1110";
		return 0;
	}
	if(s[1][2]=='A'&&s[0][2]!='B'){
		cout<<"1110";
		return 0;
	}
	if(s[1][2]=='C'&&s[0][2]!='B'){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
