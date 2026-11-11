#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ca,cb,cac,cbc;
string sa,sb;
char cas,cbs;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> ca >> sa >> cb >> sb;
	if(ca!=cb){
		cout << "0000";
		return 0;
	}
	cac = ((int)sa[0] - 48) * 10 + ((int)sa[1] - 48);
	cbc = ((int)sb[0] - 48) * 10 + ((int)sb[1] - 48);
	cas = sa[2];cbs = sb[2];
	if(cac!=cbc){
		cout << 1000;
		return 0;
	}
	if((cas>='D'&&cbs>='D')||(cas<='C'&&cbs<='C')){
		if((cas-cbs==1||cbs-cas==1)||(cas=='D'&&cbs=='F')||(cbs=='F'&&cas=='D')){
			cout << 1111;
		}else{
			cout << 1110;
		}
	}else{
		cout << 1100;
	}

	return 0;
}
