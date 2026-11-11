#include<bits/stdc++.h>
using namespace std;
int r_car,x_car,nrs,nxs,nr,nx;
char r_set,x_set;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r_car>>nr>>r_set>>x_car>>nx>>x_set;
	nrs=(int)r_set;
	nxs=(int)x_set;
	if(r_car==x_car){
		cout<<1;
		if(nx==nr){
			cout<<1;
		}else{
			cout<<0;
		}if(nx==nr&&nrs+nxs<=132||nx==nr&&nrs+nxs==137){
			cout<<1;
		}else{
			cout<<0;
		}if(nx==nr&&nrs+nxs==131||nx==nr&&nrs+nxs==133||nx==nr&&nrs+nxs==137){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	
	return 0;
}

