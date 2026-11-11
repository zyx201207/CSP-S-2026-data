#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rz,xc,xz;//R的车和座，X的车和座
	cin>>rc>>rz>>xc>>xz;
	bool tong_che=true;
	if(rc==xc) cout<<1;
	else{
		cout<<0;
		tong_che=false;
	}
	if(tong_che and rz[0]==xz[0] and rz[1]==xz[1]) cout<<1;
	else cout<<0;
	if(tong_che and rz[0]==xz[0] and rz[1]==xz[1] ){
		if(((rz[2]=='A' or rz[2]=='B' or rz[2]=='C')and(xz[2]=='A' or xz[2]=='B' or xz[2]=='C')) or ((rz[2]=='D' or rz[2]=='F')and(xz[2]=='D' or xz[2]=='F'))){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	int rnum=0,xnum=0,ry=0,xy=0;
	rnum=(rz[0]-'0')*10+rz[1]-'0';
	xnum=(xz[0]-'0')*10+xz[1]-'0';
	if(rz[2]=='A') ry=1;
	if(rz[2]=='B') ry=2;
	if(rz[2]=='C') ry=3;
	if(rz[2]=='D') ry=4;
	if(rz[2]=='F') ry=5;
	
	if(xz[2]=='A') xy=1;
	if(xz[2]=='B') xy=2;
	if(xz[2]=='C') xy=3;
	if(xz[2]=='D') xy=4;
	if(xz[2]=='F') xy=5;
	
	bool tce=false;
	if(((rz[2]=='A' or rz[2]=='B' or rz[2]=='C')and(xz[2]=='A' or xz[2]=='B' or xz[2]=='C')) or ((rz[2]=='D' or rz[2]=='F')and(xz[2]=='D' or xz[2]=='F'))){
		tce=true;
	}
	if(tce and(((ry-xy)*(ry-xy)==1 and rnum==xnum)or (ry==xy and (rnum-xnum)*(rnum-xnum)==1))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
