#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,xc,rz,xz;
	cin>>rc>>rz>>xc>>xz;
	if(rc==xc){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	
	if(rz[0]==xz[0]&&rz[1]==xz[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	
	if((rz[2]<='C'&&xz[2]<='C')||(rz[2]>='D'&&xz[2]>='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	
	char mx,mi;
	if(xz[2]>rz[2]){
		mx=xz[2],mi=rz[2];
	}else{
		mx=rz[2],mi=xz[2];
	}
	if(mx-mi==1&&mx!='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
