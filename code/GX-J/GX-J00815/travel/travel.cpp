#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rc,xc;
	bool a,b,c;
	string rz,xz;
	cin>>rc>>rz>>xc>>xz;
	if(rc==xc){
        cout<<1;
        a=true;
	}
	else{
        cout<<0;
	}
    if(rz[0]==xz[0] && rz[1]==xz[1] && a){
        cout<<1;
        b=true;
    }
    else{
        cout<<0;
    }
    if(b && (rz[2]<='C' && xz[2]<='C') || (rz[2]>='D' && xz[2]>='D')){
        cout<<1;
        c=true;
    }
    else{
        cout<<0;
    }
    if(rz[2]>='D' && xz[2]>='D' && c){
        cout<<1;
    }
    else if(abs(rz[2]-xz[2])==1 &&c){
        cout<<1;
    }
    else{
        cout<<0;
    }
}
