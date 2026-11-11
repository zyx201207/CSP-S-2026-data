#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rx,rz,xx,xz;
	cin>>rx>>rz>>xx>>xz;
	int rxn=0,xxn=0,rzn=0,xzn=0;
	for(int i=0;i<rx.size();i++){
		if(rx[i]>='0'&&rx[i]<='9'){
			rxn=rxn*10+rx[i]-'0';
		}
		if(xx[i]>='0'&&xx[i]<='9'){
			xxn=xxn*10+xx[i]-'0';
		}
	}
	if(rxn==xxn){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(rz[i]>='0'&&rz[i]<='9'){
			rzn=rzn*10+rz[i]-'0';
		}
		if(xz[i]>='0'&&xz[i]<='9'){
			xzn=xzn*10+xz[i]-'0';
		}
	}
	if(rzn==xzn){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	char rc=rz[rz.size()-1],xc=xz[xz.size()-1];
	if(!((rc=='C'&&xc=='D')||(rc=='D'&&xc=='C'))){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(xc==rc+1||rc==xc+1||(rc=='D'&&xc=='F')||(rc=='F'&&xc=='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
//100
