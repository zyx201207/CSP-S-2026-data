#include<bits/stdc++.h>
using namespace std;
//Trick||Treat!
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	string p1=s1.substr(0,2);
	string p2=s2.substr(0,2);
	if(p1==p2) cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	char k1=s1[2],k2=s2[2];
	if(k1>='A'&&k1<='C'){
		if(k2>='A'&&k2<='C'&&k1!=k2) {
			cout<<"1";
			if(k1=='A'){
				if(k2=='B') cout<<"1";
				else cout<<"0";
			}
			else if(k1=='B'){
				cout<<"1";
			}
			else if(k1=='C'){
				if(k2=='B') cout<<"1";
				else cout<<"0";
			}
			
		}
		else {
			cout<<"00";
			return 0;
		}
	}
	else{
		if(k2>='D'&&k2<='F'&&k1!=k2) {
			cout<<"11";
		}
		else {
			cout<<"00";
			return 0;
		}
	}
	//cout<<ans;
	return 0;
}
