#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rx,rz,xx,xz,rp,xp;
    cin>>rx>>rz>>xx>>xz;
    rp=rz[0]+rz[1];
    xp=xz[0]+xz[1];
    int rc=0,xc=0;
    if(rz[2]=='A' || rz[2]=='B' || rz[2]=='C'){
    	rc=1;
	}
	if(xz[2]=='A' || xz[2]=='B' || xz[2]=='C'){
    	xc=1;
	}
    if(rx==xx){
        cout<<'1';
    }
    else{
    	cout<<"0000";
    	return 0;
	}
    if(rp==xp){
        cout<<'1';
    }
    else{
    	cout<<"000";
    	return 0;
	}
    if(rc==xc){
    	cout<<'1';
	}
	else{
		cout<<"00";
		return 0;
	}
	if((rc==1 &&(rz[2]-1==xz[2] || rz[2]+1==xz[2])) || (rc==0 &&(rz[2]-2==xz[2] || rz[2]+2==xz[2]))){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
    return 0;
}
