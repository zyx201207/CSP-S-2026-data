#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<"1";
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			cout<<"1";
			int a3,b3;
			if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C') a3=1;
			else a3=2;
			if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C') b3=1;
			else b3=2;
			if(a3==b3){
				cout<<"1";
				if(a2[2]-b2[2]==1||a2[2]-b2[2]==-1||a3==2){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
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
	return 0;
}