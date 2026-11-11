#include<bits/stdc++.h>
using namespace std;
inline bool isNear(char a,char b) {
	if((a<='C'&&b<='C') || (a>'C'&&b>'C')) return true;
	else return false;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rs,xc,xs,ans;
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc) ans+="1";
	else {
		cout<<"0000";
		return 0;
	}
	if(rs[0]==xs[0] && rs[1]==xs[1]) ans+="1";
	else {
		cout<<"1000";
		return 0;
	}
	if(isNear(rs[2],xs[2])) ans+="1";
	else {
		cout<<"1100";
		return 0;
	}
	if((int)rs[2]-(int)xs[2]==-1 || (int)rs[2]-(int)xs[2]==1) ans+="1";
	else ans+="0";
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
