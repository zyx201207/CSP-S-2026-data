#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rz,xc,xz;
	bool cx,p,g,x;
	int xr,xx;
	cin>>rc>>rz>>xc>>xz;
	int j1=0;
	for(int i=0;i<2;i++){
		if(rc[i]==xc[i]){
			j1++;
		}
	}
	if(j1==2){
		cx=true;
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int j2=0;
	for(int i=0;i<2;i++){
		if(rz[i]==xz[i]){
			j2++;
		}
	}
	if(j2==2){
		cout<<1;
		p=true;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(rz[3]=='A'||rz[3]=='B'||rz[3]=='C'){
		xr=1;
	}else{
		xr=0;
	}
	if(xz[3]=='A'||xz[3]=='B'||xz[3]=='C'){
		xx=1;
	}else{
		xx=0;
	}
	if(xr^xx){
		g=true;
		cout<<1;
	}else{
		g=false;
		cout<<0<<0;
		return 0;
	}
	if(rz[3]+1==xz[3]||rz[3]-1==xz[3]){
		x=true;
		cout<<1;
	}
	else{
		x=false;
		cout<<0;
	}
	return 0;
}
