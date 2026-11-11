#include <bits/stdc++.h>
using namespace std;
string ac,az,bc,bz;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ac>>az>>bc>>bz;
    if(ac==bc){
        cout<<"1";
    }
    else{
		cout<<"0000";
		return 0;
	}
    if(az[0]==bz[0]&&az[1]==bz[1]){
        cout<<"1";
    }
    else cout<<"0";
    if(az[2]>='A'&&az[2]<='C'&&bz[2]>='D'&&bz[2]<='F'||bz[2]>='A'&&bz[2]<='C'&&az[2]>='D'&&az[2]<='F'){
    	cout<<"0";
	}
	else{
		if(az[0]==bz[0]&&az[1]==bz[1]){
	        cout<<"1";
	    }
	    else cout<<"0";
	}
    if((az[2]=='C'&&bz[2]=='D')||(az[2]=='D'&&bz[2]=='C')){
    	cout<<"0";
	}
	else if(az[2]=='F'&&bz[2]=='D'||az[2]=='D'&&bz[2]=='F'){
		if(az[0]==bz[0]&&az[1]==bz[1]){
	        cout<<"1";
	    }
	    else cout<<"0";
	}
	else if(az[2]-bz[2]==1||bz[2]-az[2]==1){
		if(az[0]==bz[0]&&az[1]==bz[1]){
			cout<<"1";
	    }
	    else cout<<"0";
	}
	else cout<<"0";
    return 0;
}
