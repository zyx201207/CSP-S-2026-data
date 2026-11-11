#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int car_a,car_b;
	string seat_a,seat_b;
	cin>>car_a>>seat_a>>car_b>>seat_b;
	if(car_a==car_b){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if((seat_a[0]==seat_b[0]) && (seat_a[1]==seat_b[1])){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(((seat_a[2]<='C')&&(seat_b[2]<='C'))||((seat_a[2]>='D')&&(seat_b[2]>='D'))){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((abs(int(seat_a[2]-seat_b[2]))==1) || ((seat_a[2]>='D')&&(seat_b[2]>='D'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
