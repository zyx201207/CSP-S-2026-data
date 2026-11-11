#include <bits/stdc++.h>
using namespace std;
string rche,rzuo,xche,xzuo;
string rpai="0000",xpai="0000";
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	
	cin>>rche>>rzuo>>xche>>xzuo;
	if(rche==xche){
		cout<<1;
		
		rpai[0]=rzuo[0];
		rpai[1]=rzuo[1];
		xpai[0]=xzuo[0];
		xpai[1]=xzuo[1];
		
		if(rpai==xpai){
			cout<<'1';
			if((rzuo[2]<'D' && xzuo[2]<'D') || (rzuo[2]>='D' && xzuo[2]>='D')){
				cout<<'1';
				if((rzuo[2]-xzuo[2]==1) || (rzuo[2]-xzuo[2]==-1)){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	
	return 0;
}
