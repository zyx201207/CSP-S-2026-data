#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool check1() {
	char i=b[2],j=d[2];
	if (i>j) swap(i,j);
	if (i=='A' && j=='B') return 1;
	if (i=='A' && j=='C') return 1;
	if (i=='B' && j=='C') return 1;
	if (i=='D' && j=='F') return 1;
	return 0;
}
bool check2() {
	char i=b[2],j=d[2];
	if (i>j) swap(i,j);
	if (i=='A' && j=='B') return 1;
	if (i=='B' && j=='C') return 1;
	if (i=='D' && j=='F') return 1;
	return 0;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if (a==c) {
		cout<<1;
		if (b[0]==d[0] && b[1]==d[1]) {
			cout<<1;
			if (check1()) {
				cout<<1;
				if (check2()) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
