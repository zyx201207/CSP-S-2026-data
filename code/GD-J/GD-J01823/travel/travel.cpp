#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rz,xc,xz;
	cin>>rc>>rz>>xc>>xz;
	bool flag=true;
	for(int i=0;i<2;i++){
		int k=(int)(rc[i]-'0');
		int r=(int)(xc[i]-'0');
		if(k!=r){
			flag=false;
		}
	}
	if(!flag){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	for(int i=0;i<2;i++){
		int k=(int)(rz[i]-'0');
		int r=(int)(xz[i]-'0');
		if(k!=r){
			flag=false;
		}
	}
	if(!flag){
		cout<<"000";
		return 0;
	}else{
		cout<<"1";
	}
	if((rz[2]>='A'&&rz[2]<='C')&&(xz[2]>='A'&&xz[2]<='C')){
		cout<<"1";
	}else if((rz[2]>='D'&&rz[2]<='F')&&(xz[2]>='D'&&xz[2]<='F')){
		cout<<"11";
		return 0;
	}else{
		cout<<"00";
		return 0;
	}
	int v=(int)(rz[2]-'A');
	int h=(int)(xz[2]-'A');
	if(abs(h-v)==1){
		cout<<"1";
	}else{
		cout<<"0";
	} 
	return 0;
}

