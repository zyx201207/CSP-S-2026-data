#include<bits/stdc++.h>
using namespace std;
string az,bz;
int ac,bc;
int main(){
	freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
	cin>>ac>>az>>bc>>bz;
	if(ac==bc){
		cout<<1;
	}else{
		cout<<0;
	}
	if(ac==bc && az[0]==bz[0] && az[1]==bz[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(ac==bc && az[0]==bz[0] && az[1]==bz[1] && ((az[2]<='C' && bz[2]<='C')||(az[2]>='D' && bz[2]>='D'))){
		cout<<1;
	}else{
		cout<<0;
	}
	if(ac==bc && az[0]==bz[0] && az[1]==bz[1] && ((az[2]<='C' && bz[2]<='C')||(az[2]>='D' && bz[2]>='D')) && (az[2]-bz[2]==1 || bz[2]-az[2]==1)){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
	   // freopen("travel.out","w",stdout);
}
