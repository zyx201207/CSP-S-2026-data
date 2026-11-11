#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cy,ct,dy,dt;
	cin>>cy>>ct>>dy>>dt;
	if(cy==dy){
		cout<<"1";
		if(ct[0]==dt[0]&&ct[1]==dt[1]){
			cout<<"1";
			if((ct[2]=='F'&&dt[2]=='D')||(ct[2]=='D'&&dt[2]=='F')||(ct[2]=='A'&&dt[2]=='B')||(ct[2]=='A'&&dt[2]=='C')||(ct[2]=='B'&&dt[3]=='A')||(ct[3]=='B'&&dt[2]=='C')||(ct[2]=='C'&&dt[2]=='A')||(ct[2]=='C'&&dt[2]=='B'))cout<<1;
			else cout<<"0";
			if((ct[2]=='F'&&dt[2]=='D')||(ct[2]=='D'&&dt[2]=='F')||(ct[2]=='A'&&dt[2]=='B')||(ct[2]=='B'&&dt[2]=='A')||(ct[2]=='B'&&dt[3]=='C')||ct[3]=='C'&&dt[2]=='B')cout<<1;
			else cout<<"0";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
