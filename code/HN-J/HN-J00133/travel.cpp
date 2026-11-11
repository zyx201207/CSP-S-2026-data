#include<bits/stdc++.h>
using namespace std;
string r,rz,x,xz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>rz>>x>>xz;
	if(r==x){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(rz.substr(0,2)==xz.substr(0,2)){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	if(rz[2]<'D'&&xz[2]<'D'){
		cout<<'1';
		if(rz[2]-xz[2]==1||rz[2]-xz[2]==-1){
			cout<<'1';
		}else{
			cout<<'0';
		}	
	}else if(rz[2]>='D'&&xz[2]>='D'){
		cout<<"11";
	}else{
		cout<<"00";
	}
	return 0;
}
