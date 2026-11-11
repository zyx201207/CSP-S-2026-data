#include<bits/stdc++.h>
using namespace std;
string xR1,xR2,xX1,xX2;
int cx1,cx2,zw1,zw2,ph1,ph2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xR1>>xR2>>xX1>>xX2;
	for(int i = 0;i < 2;i++){
		cx1 *= 10;
		cx1 += (xR1[i] - '0');
		cx2 *= 10;
		cx2 += (xX1[i] - '0');
		ph1 *= 10;
		ph1 += (xR2[i] - '0');
		ph2 *= 10;
		ph2 += (xX2[i] - '0');
	}
	if(cx1 != cx2){
		cout<<"0000";
	}else if(ph1 != ph2){
		cout<<"1000";
	}else{
		cout<<"11";
		if(xR2[2] == 'A'){
			if(xX2[2] == 'B' || xX2[2] == 'C'){
				if(xX2[2] == 'B'){
					cout<<"11";
				}else{
					cout<<"10";
				}
			}else{
				cout<<"00";
			}
		}else if(xR2[2] == 'B'){
			if(xX2[2] == 'A' || xX2[2] == 'C'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else if(xR2[2] == 'C'){
			if(xX2[2] == 'A' || xX2[2] == 'B'){
				if(xX2[2] == 'B'){
					cout<<"11";
				}else{
					cout<<"10";
				}
			}else{
				cout<<"00";
			}
		}else if(xR2[2] == 'D'){
			if(xX2[2] == 'F'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else if(xR2[2] == 'F'){
			if(xX2[2] == 'D'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}
	}
	return 0;
}
