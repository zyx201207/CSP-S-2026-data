#include<bits/stdc++.h>

using namespace std;
string a,b,c,d;
bool calc(char c,char t){
	if(c=='A' && t=='B' || c=='A' && t=='C'
	 || c=='B' && t=='A' || c=='B' && t=='C'
	 || c=='C' && t=='A' || c=='C' && t=='B') return 1;
	if(c=='D' && t=='F' || c=='F' && t=='D') return 1;
	return 0;
}
bool check(char c,char t){
	if(c=='A' && t=='B' || c=='B' && t=='A') return 1;
	if(c=='B' && t=='C' || c=='C' && t=='B') return 1;
	if(c=='D' && t=='F' || c=='F' && t=='D') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b.substr(0,2)==d.substr(0,2)){
			cout<<"1";
			if(calc(b[2],d[2])){
				cout<<"1";
				if(check(b[2],d[2])){
					cout<<"1";
				}else cout<<"0";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
