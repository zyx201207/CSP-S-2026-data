#include<bits/stdc++.h>
using namespace std;
int rc,xc;
string rz,xz;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>rc>>rz>>xc>>xz;
	if(rc==xc){
		cout<<1;
		if(rz[0]==xz[0] && rz[1]==xz[1]){
			cout<<1;
			if(rz[2]=='A' && xz[2]=='B') cout<<"11";
			else if(rz[2]=='B' && (xz[2]=='A' || xz[2]=='C')) cout<<"11";
			else if(rz[2]=='C' && xz[2]=='B') cout<<"11";
			else if(rz[2]=='D' && xz[2]=='F') cout<<"11";
			else if(rz[2]=='F' && xz[2]=='D') cout<<"11";
			else if(rz[2]=='A' && xz[2]=='C') cout<<"10";
			else if(rz[2]=='C' && xz[2]=='A') cout<<"10";
			else cout<<"00";
		}else
			cout<<"000";
	}else
		cout<<"0000";
		
	return 0;	
}