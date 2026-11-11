#include<bits/stdc++.h>
using namespace std;
string ax,az,bx,bz;
bool f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ax>>az>>bx>>bz;
	for(int i=0;i<2;i++){
		if(ax[i]!=bx[i])f=true;
	}	
	if(f==true){
		cout<<"0000";
		return 0;
	}
	f=false;
	for(int i=0;i<2;i++){
		if(az[i]!=bz[i])f=true;
	}
	if(f==true){
		cout<<"1000";
		return 0;
	}
	f=false;
	if(az[2]>='A'&&az[2]<='C'){
		if(bz[2]>='A'&&bz[2]<='C'){
			if(az[2]=='B'||bz[2]=='B'){
				cout<<"1111";
				return 0;
			}
			else{
				cout<<"1110";
				return 0;
			}
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	if(az[2]>='D'&&az[2]<='F'){
		if(bz[2]>='D'&&bz[2]<='F'){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	return 0;
}
