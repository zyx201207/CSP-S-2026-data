#include<bits/stdc++.h>
using namespace std;
string ax,bx,az,bz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ax>>az>>bx>>bz;
	if(ax==bx){
		cout<<1;
		if(az[0]==bz[0]&&az[1]==bz[1]){
			cout<<1;
			if(az[2]<='C'&&bz[2]<='C'||az[2]>'C'&&bz[2]>'C'){
				cout<<1;
				if(abs(az[2]-bz[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
