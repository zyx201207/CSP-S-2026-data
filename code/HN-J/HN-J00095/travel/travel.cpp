#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,az,b,bz;
	int l=0;
	cin>>a>>az>>b>>bz;
	if(a==b) {
		cout<<1;
	} else {
		cout<<"0000";
		return 0;
	}
	if(az[0]+az[1]==bz[0]+bz[1]) {
		cout<<1;
	} else {
		cout<<"000";
		return 0;
	}

	if(az[2]=='D'&&bz[2]=='F') {
		cout<<1;
		l++;
	} else {
		if(az[2]=='F'&&bz[2]=='D') {
			cout<<1;
			l++;
		}
	}
	if(az[2]=='A') {
		if(bz[2]=='B'||bz[2]=='C') {
			cout<<1;
			l++;
		}
	} 
	if(az[2]=='B') {
		if(bz[2]=='A'||bz[2]=='C') {
			cout<<1;
			l++;
		}
	} 
	if(az[2]=='C') {
		if(bz[2]=='A'||bz[2]=='B') {
			cout<<1;
			l++;
		}
	} 
	if(l==0){
		cout<<"00";
		return 0;
	}
	if(az[2]==bz[2]+1||az[2]+1==bz[2]) cout<<1;
	else cout<<0;
	return 0;
}
