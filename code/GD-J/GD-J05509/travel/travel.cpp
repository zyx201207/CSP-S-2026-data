#include<bits/stdc++.h>
using namespace std;
long long a;
string c[10],s[10];
bool si(long long a){
	if(s[a][2]=='D'||s[a][2]=='F')return 1;
	return 0;
}
long long num(long long a){
	if(s[a][2]=='A')return 1;
	if(s[a][2]=='B')return 2;
	if(s[a][2]=='C')return 3;
	if(s[a][2]=='D')return 5;
	return 6;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]==c[2]){
		cout<<'1';
		if(s[1][0]==s[2][0]&&s[1][1]==s[2][1]){
			cout<<'1';
			if(si(1)==si(2)){
				cout<<'1';
				if(abs(num(1)-num(2))==1)cout<<'1';
				else cout<<'0';
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else cout<<"0000";
	return 0;
}
