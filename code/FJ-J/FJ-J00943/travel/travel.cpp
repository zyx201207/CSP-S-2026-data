#include<bits/stdc++.h>
using namespace std;
string rc,rn,xc,xn;
int main(){
	freopen("travel.in" ,"r",stdin);
	freopen("travel.out" ,"w",stdout);
	cin>>rc>>rn>>xc>>xn;
	if(rc==xc){
		cout<<1;
		if(rn[0]==xn[0]&&rn[1]==xn[1]){
			cout<<1;
			if(rn[2]-'A'-'0'<3&&xn[2]-'A'-'0'<3||rn[2]-'A'-'0'>=3&&xn[2]-'A'-'0'>=3){
				cout<<1;
				if(rn[2]-xn[2]-'0'==1||xn[2]-rn[2]-'0'==1)cout<<1;
				else {
					cout<<0;
					return 0;
				}
			}else {
				cout<<"00";
				return 0;
			}
		}else {
			cout<<"000";
			return 0;
		}
	}else {
		cout<<"0000";
		return 0;
	}
	return 0;
}
