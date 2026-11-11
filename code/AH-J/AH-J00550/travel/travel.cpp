#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ac,az,bc,bz;
	cin>>ac>>az>>bc>>bz;
	if(ac==bc){
		cout<<1;
		if(az[1]==bz[1]&&az[0]==bz[0]){ 
			cout<<1;
			if((az[2]=='A'&&bz[2]=='B')||(az[2]=='B'&&bz[2]=='A')||(az[2]=='B'&&bz[2]=='C')||(az[2]=='C'&&bz[2]=='B')||(az[2]=='C'&&bz[2]=='A')||(az[2]=='A'&&bz[2]=='C')||(az[2]=='D'&&bz[2]=='F')||(az[2]=='F'&&bz[2]=='D')){
				cout<<1;
				if((az[2]=='A'&&bz[2]=='B')||(az[2]=='B'&&bz[2]=='A')||(az[2]=='B'&&bz[2]=='C')||(az[2]=='C'&&bz[2]=='B')||(az[2]=='D'&&bz[2]=='F')||(az[2]=='F'&&bz[2]=='D'))cout<<1;
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
