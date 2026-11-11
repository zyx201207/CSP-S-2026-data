#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rc,xc;
	char rz[4],xz[4];
	cin>>rc;
	for(int i=1;i<=3;i++){
		cin>>rz[i];
	}
	cin>>xc;
	for(int i=1;i<=3;i++){
		cin>>xz[i];
	}
	if(rc==xc)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(rz[1]==xz[1]&&rz[2]==xz[2]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((rz[3]<='C'&&xz[3]<='C')||(rz[3]>='D'&&xz[3]>='D'))cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(rz[3]-xz[3]==1||xz[3]-rz[3]==1)cout<<"1";
	else cout<<"0";
	return 0;
} 
