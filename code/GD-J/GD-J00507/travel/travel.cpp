#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string seat1,seat2;
	int car1,car2;
	int co1[3];
	int co2[3];
	cin>>car1>>seat1>>car2>>seat2;
	
	int line1=(int)(seat1[0])*10+(int)(seat1[1]);
	int line2=(int)(seat2[0])*10+(int)(seat2[1]);
	
	if(seat1[2]=='A'){co1[2]=0;co1[1]=1;}
	else if(seat1[2]=='B'){co1[2]=1;co1[1]=1;}
	else if(seat1[2]=='C'){co1[2]=2;co1[1]=1;}
	else if(seat1[2]=='D'){co1[2]=4;co1[1]=2;}
	else{co1[2]=5;co1[1]=2;}
	
	if(seat2[2]=='A'){co2[2]=0;co2[1]=1;}
	else if(seat2[2]=='B'){co2[2]=1;co2[1]=1;}
	else if(seat2[2]=='C'){co2[2]=2;co2[1]=1;}
	else if(seat2[2]=='D'){co2[2]=4;co2[1]=2;}
	else{co2[2]=5;co2[1]=2;}
	
	if(car1==car2)cout<<1;
	else{cout<<0;}
	
	if(car1==car2&&line1==line2)cout<<1;
	else{cout<<0;}
	
	if(car1==car2&&co1[1]==co2[1]&&line1==line2)cout<<1;
	else{cout<<0;}
	
	if(car1==car2&&co1[1]==co2[1]&&line1==line2&&(co1[2]-co2[2]==1||co1[2]-co2[2]==-1))cout<<1;
	else{cout<<0;}
	
	return 0;
}
