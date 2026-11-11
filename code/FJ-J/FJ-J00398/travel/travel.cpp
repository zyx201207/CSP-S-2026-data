#include <bits/stdc++.h>
using namespace std;
char cinp1,cinp2,sinp1,sinp2,sinp3,cinp3,cinp4,sinp4,sinp5,sinp6;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cinp1>>cinp2>>sinp1>>sinp2>>sinp3>>cinp3>>cinp4>>sinp4>>sinp5>>sinp6;
	if(cinp1==cinp3 && cinp2==cinp4){
		cout<<"1";
		if(sinp1==sinp4 && sinp2==sinp5){
			cout<<"1";
			if((sinp3<='C' && sinp6<='C') || (sinp3>='D' && sinp6>='D')){
				cout<<"1";
				if(abs(int(sinp3-sinp6))==1)
					cout<<"1";
				else
					cout<<"0";
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";	
	}
	else
		cout<<"0000";
	return 0;
}
