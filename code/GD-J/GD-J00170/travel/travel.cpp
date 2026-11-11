#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int carr,carx;
	string seatr,seatx;
	cin >> carr >> seatr >> carx >> seatx;
	int lr,lx,sr,sx;
	lr=(seatr[1]-'0')*10+seatr[0]-'0';
	lx=(seatx[1]-'0')*10+seatx[0]-'0';
	sr=seatr[2]-'A';
	sx=seatx[2]-'A';
	if(sr==5)sr=4;
	if(sx==5)sx=4;
	if(carr!=carx)cout << "0000";
	else if(lr!=lx)cout << "1000";
	else if(!((sr>=3&&sx>=3)||(sr<=2&&sx<=2)))cout << "1100";
	else if(!(((sr-sx)==1||(sr-sx)==-1)&&(sx+sr!=5)))cout << "1110";
	else cout << "1111";
	return 0;
} 
