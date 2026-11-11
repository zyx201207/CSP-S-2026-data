#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ac,bc;
	string az,bz;
	cin>>ac>>az>>bc>>bz;
	if(ac==bc){
		cout<<1<<"";
		if(az.substr(0,2)==bz.substr(0,2)){
		cout<<1<<"";
		if((az[2]<'D' &&bz[2]<'D')||(az[2]>='D' && bz[2]>='D')){
			cout<<1<<"";
			if(az[2]>='D' && bz[2]>='D'){
				cout<<1;
			}else if(az[2]-bz[2]==1 || az[2]-bz[2]==(-1)){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0<<""<<0;
		}
		}else{
		cout<<0<<""<<0<<""<<0<<"";
		}
	}else{
		cout<<0<<""<<0<<""<<0<<""<<0;
	}
	return 0;
} 
