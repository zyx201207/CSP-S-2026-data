#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rid,xid,rz=0,xz=0;
	string r,x,rc="",xc="";
	cin>> rid >> r >> xid >> x;
	if(rid==xid){
		cout<< "1";
	}else{
		cout<< "0000";
		return 0;
	}
	rz=(r[0]-'0')*10+(r[1]-'0');
	xz=(x[0]-'0')*10+(x[1]-'0');
	if(rz==xz){
		cout<< "1";
	}else{
		cout<< "000";
		return 0;
	}
	rc=r[2];
	xc=x[2];
	if((rc=="A" && (xc=="B" || xc=="C")) || (rc=="B" && (xc=="A" || xc=="C")) || (rc=="C" && (xc=="B" || xc=="A")) || (rc=="D" && xc=="F") || (rc=="F" && xc=="D")){
		cout<< "1";
	}else{
		cout<< "00";
		return 0;
	}
	if(rc=="D" || rc=="F" || (rc=="A" && xc=="B") || (rc=="B" && xc=="A") || (rc=="B" && xc=="C") || (rc=="C" && xc=="B")){
		cout<< "1";
	}else{
		cout<< "0";
		return 0;
	}
	return 0;
}
