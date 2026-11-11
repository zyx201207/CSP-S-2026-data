#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b;
	string x,y;
	cin>> a>>x>>b>>y;
	if (a==b) cout<<1;
	else {
	cout<<"0000";
	return 0;
	}
	if (x[1]==y[1] and x[0]==y[0]) cout<<1;
	else {
	cout<<"000";
	return 0;
	}
	if (x[2]<'D' and y[2]<'D') cout<<1;
	else if (x[2]>'C' and y[2]>'C') cout<<1;
	else {
	cout<<"00";
	return 0;
	}
	if (x[2]+1==y[2]+0 or x[2]-1==y[2]+0 )  cout<<1;
	else cout<<0;
	return 0;
}
