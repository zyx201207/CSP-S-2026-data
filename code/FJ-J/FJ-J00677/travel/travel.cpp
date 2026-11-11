#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NUM=1;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	getline(cin,s);
	string a=s.substr(0,2);
	string b=s.substr(3,3);
	string c=s.substr(7,2);
	string d=s.substr(10,3);
	if(a==c) {
		cout<<'1';
		if(b[0]==d[0]&&b[1]==d[1]) {
			cout<<'1';
			if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||
			        (b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E')) {
				cout<<'1';
				if(b[2]-d[2]==1||d[2]-b[2]==1){
					cout<<'1';
				} else{
					cout<<'0';
				}
			} else {
				cout<<"00";
			}
		} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}

