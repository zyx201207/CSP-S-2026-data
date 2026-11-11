#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string Ra,Rb,Xa,Xb;
	cin>>Ra>>Rb>>Xa>>Xb;
	if(Ra==Xa){
		cout<<"1";
		if(Rb[0]+Rb[1]==Xb[0]+Xb[1]){
		cout<<"1";
			if((Rb[2]=="D"&&Xb[2]=="C")&&!(Rb[2]=="C"&&Xb[2]=="D")){
				cout<<"1";
				if(abs(Rb[2]-Xb[2])==1){cout<<"1";}
				else{cout<<"0";}
			}
			else{cout<<"00";}
		}
		else{cout<<"000";}
	}
	else{cout<<"0000";}









	return 0;
}
