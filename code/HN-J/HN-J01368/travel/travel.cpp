#include<bits/stdc++.h>
using namespace std;
string a,b,az,bz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>az>>b>>bz;
	if(a==b) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if((az[0]==bz[0]) && (az[1]==bz[1])) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((az[2]<='C' && bz[2]<='C')||(az[2]>='D' && bz[2]>='D')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(az[2]-bz[2]==1||az[2]-bz[2]==-1){
		cout<<1;
	}
	else{
		cout<<"0";
	}
	return 0;
}
