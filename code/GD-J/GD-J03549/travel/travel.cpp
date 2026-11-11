#include<bits/stdc++.h>
using namespace std;
map<char,bool> mp({{'A',0},{'B',0},{'C',0},{'D',1},{'F',1}});
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sx,sy,cx,cy;
	cin>>cx>>sx>>cy>>sy;
	if(cx!=cy) cout<<"0000\n";
	else if(sx.substr(0,2)!=sy.substr(0,2)) cout<<"1000\n";
	else if(mp[sx[sx.size()-1]]!=mp[sy[sy.size()-1]]) cout<<"1100\n";
	else if(sx[sx.size()-1]=='A'&&sy[sy.size()-1]=='C') cout<<"1110\n";
	else if(sx[sx.size()-1]=='C'&&sy[sy.size()-1]=='A') cout<<"1110\n";
	else cout<<"1111\n";
	return 0;
}
