#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	string sc,sz,xc,xz;
	cin>>sc>>sz>>xc>>xz;
	if(sc==xc){
		cout<<"1";
		if(sz[0]==xz[0] && sz[1]==xz[1]){
			cout<<"1";
			if((sz[2]=='A' &&xz[2]=='B') || (sz[2]=='B' &&xz[2]=='A') || (sz[2]=='B' &&xz[2]=='C') || (sz[2]=='C' &&xz[2]=='B') || (sz[2]=='D' &&xz[2]=='F') || (sz[2]=='F' &&xz[2]=='D')){
				cout<<"11";
			}else if((sz[2]=='A' &&xz[2]=='C') || (sz[2]=='C' &&xz[2]=='A')){
				cout<<"10";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
