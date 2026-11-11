#include<bits/stdc++.h>
using namespace std;
int carR,carX;
string seatR,seatX;
bool Question1(){return (carR==carX);}
bool Question2(){return (carR==carX)&&(seatR[0]==seatX[0])&&(seatR[1]==seatX[1]);}
bool Question3(){
	if(seatR[2]=='A'&&seatX[2]=='D')return false;
	if(seatR[2]=='A'&&seatX[2]=='F')return false;
	if(seatR[2]=='B'&&seatX[2]=='D')return false;
	if(seatR[2]=='B'&&seatX[2]=='F')return false;
	if(seatR[2]=='C'&&seatX[2]=='D')return false;
	if(seatR[2]=='C'&&seatX[2]=='F')return false;
	if(seatX[2]=='A'&&seatR[2]=='D')return false;
	if(seatX[2]=='A'&&seatR[2]=='F')return false;
	if(seatX[2]=='B'&&seatR[2]=='D')return false;
	if(seatX[2]=='B'&&seatR[2]=='F')return false;
	if(seatX[2]=='C'&&seatR[2]=='D')return false;
	if(seatX[2]=='C'&&seatR[2]=='F')return false;
	return (carR==carX)&&(seatR[0]==seatX[0])&&(seatR[1]==seatX[1]);
}
bool Question4(){
	if(!((carR==carX)&&(seatR[0]==seatX[0])&&(seatR[1]==seatX[1])))return false;
	if(seatR[2]=='A'&&seatX[2]=='B')return true;
	if(seatR[2]=='B'&&seatX[2]=='C')return true;
	if(seatR[2]=='D'&&seatX[2]=='F')return true;
	if(seatX[2]=='A'&&seatR[2]=='B')return true;
	if(seatX[2]=='B'&&seatR[2]=='C')return true;
	if(seatX[2]=='D'&&seatR[2]=='F')return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>carR>>seatR>>carX>>seatX;
	cout<<Question1()<<Question2()<<Question3()<<Question4()<<"\n"; 
	return 0;
}
