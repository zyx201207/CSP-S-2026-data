#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,a2,b2;


bool check1(char c1,char c2){
	if(c1<='C'&&c2<='C') return 1;
	return 0;
	
}
bool check2(char c1,char c2){
	if(c1=='A'&&c2=='B') return 1;
	if(c1=='B'&&c2=='A') return 1;
	if(c1=='B'&&c2=='C') return 1;
	if(c1=='C'&&c2=='B') return 1;
	if(c1=='D'&&c2=='F') return 1;
	if(c1=='F'&&c2=='D') return 1;
	return 0; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a2>>b>>b2;
	if(a==b){
		cout<<"1";
		if(a2[1]==b2[1]&&a2[0]==b2[0]){
			cout<<"1";
			if(check1(a2[2],b2[2])){
				cout<<"1";
				if(check2(a2[2],b2[2])){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
