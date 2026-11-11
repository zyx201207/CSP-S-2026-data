#include<bits/stdc++.h>
#define int long long
using namespace std;
string rc,rs,xc,xs;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc){
		cout<<"1";
		string rst="",xst="";
		rst+=rs[0],rst+=rs[1],xst+=xs[0],xst+=xs[1];
		char rss=rs[2],xss=xs[2];
		if(rst==xst){
			cout<<"1";
			if(rss<'D' && xss<'D') {
				cout<<"1";
				if(abs(rss-xss)==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0; 
}
