#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rc,xc,rh,xh,r,z;
	string rz,xz;
	cin>>rc>>rz>>xc>>xz;
	rh=(rz[0]-'0')*10+(rz[1]-'0');
	xh=(xz[0]-'0')*10+(xz[1]-'0');
	r=rz[2]-'A'+1;
	z=xz[2]-'A'+1;
	if(rc!=xc){
		cout<<"0000";
		return 0;
	}else{
		cout<<'1';
		if(rh!=xh){
			cout<<"000";
			return 0;
		}else{
			cout<<'1';
			if(r>=1&&r<=3&&z>=1&&z<=3){
				cout<<'1';
				if(r-z==1||z-r==1){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else if(z>=4&&z<=5&&r>=4&&r<=5){
				cout<<'1';
				if(r-z==1||z-r==1){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00";
				return 0;
			}
		}
	}
	return 0;
}
