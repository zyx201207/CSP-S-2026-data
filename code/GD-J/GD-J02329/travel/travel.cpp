#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>c1>>s1>>c2>>s2;
	a=s1.substr(0,2);
	b=s2.substr(0,2);
	if(c1==c2){
		cout <<"1";
		if(a==b){
			cout <<"1";
			if(s1[2]<=67&&s2[2]<=67||s1[2]>=68&&s2[2]>=68){
				cout <<"1";
				if(s1[2]>=68&&s2[2]>=68){
					cout <<"1";
				}
				else if(s1[2]=='B'||s2[2]=='B') {
					cout<<1;}
				else {cout<<"0";}
			}
			else cout <<"00";
		}
		else cout <<"000";
	}
	else cout <<"0000";
	return 0;
} 
