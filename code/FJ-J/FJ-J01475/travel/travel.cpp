#include<bits/stdc++.h>
using namespace std;
string cara,seata,carb,seatb;
int flagh;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cara>>seata>>carb>>seatb;
	if(cara==carb) cout<<1;
	else{
		cout<<"0000";
		return 0;	
	}
	if(seata[0]==seatb[0]&&seata[1]==seatb[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((seata[2]<='C'&&seata[2]>='A')&&(seatb[2]<='C'&&seatb[2]>='A')){
		cout<<1;
		flagh=1;
	}else if((seata[2]<='F'&&seata[2]>='D')&&(seata[2]<='F'&&seata[2]>='D')){
		cout<<1;
 	}else{
		cout<<"00";
		return 0; 
	} 
	if(flagh==1){
		if((seata[2]=='C'&&seatb[2]=='A')||(seata[2]=='A'&&seatb[2]=='C')){
			cout<<0;
			return 0;
		}else{
			cout<<1;
		}
	}else{
		cout<<1;
	}
	return 0;
}
