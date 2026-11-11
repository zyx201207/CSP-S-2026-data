#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rz,xc,xz;
	cin>>rc>>rz>>xc>>xz;
	if(rc==xc){
		cout<<"1";}else{cout<<"0";}
		if((rz.substr(0,2)==xz.substr(0,2))&&(rc==xc)){
		cout<<"1";}else{cout<<"0";}
		if(((((rz[2]>='A'&&rz[2]<='C')&&(xz[2]>='A'&&xz[2]<='C'))||((rz[2]>='D'&&rz[2]<='F')&&(xz[2]>='D'&&xz[2]<='F')))&&(rz.substr(0,2)==xz.substr(0,2)))&&(rc==xc)){
		cout<<"1";}else{cout<<"0";}
		if(((((int(rz[2])-int(xz[2])==1)||(int(rz[2])-int(xz[2])==-1))&&(((rz[2]>='A'&&rz[2]<='C')&&(xz[2]>='A'&&xz[2]<='C'))||((rz[2]>='D'&&rz[2]<='F')&&(xz[2]>='D'&&xz[2]<='F'))))&&(rz.substr(0,2)==xz.substr(0,2)))&&(rc==xc)){
		cout<<"1";}else{cout<<"0";}return 0;
}