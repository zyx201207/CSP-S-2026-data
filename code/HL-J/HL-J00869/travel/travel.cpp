#include<bits/stdc++.h>
using namespace std;
#define int long long
int rc,xc;
string rz,xz;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>rc>>rz>>xc>>xz;
	if(rc==xc){
		cout<<"1";
		if(rz[0]==xz[0]&&rz[1]==xz[1]){
			cout<<"1";
			if((rz[2]=='A'&&xz[2]=='B')||(rz[2]=='A'&&xz[2]=='C')||(rz[2]=='B'&&xz[2]=='C')||(rz[2]=='B'&&xz[2]=='A')||(rz[2]=='C'&&xz[2]=='B')||(rz[2]=='C'&&xz[2]=='A')||(rz[2]=='D'&&xz[2]=='F')||(rz[2]=='F'&&xz[2]=='D')){
				cout<<"1";
				if((rz[2]=='A'&&xz[2]=='B')||(rz[2]=='B'&&xz[2]=='A')||(rz[2]=='B'&&xz[2]=='C')||(rz[2]=='C'&&xz[2]=='B')||(rz[2]=='D'&&xz[2]=='F')||(rz[2]=='F'&&xz[2]=='D')){
					cout<<"1";
					return 0;
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
