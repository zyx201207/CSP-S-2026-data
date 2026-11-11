#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string car1,car2,seat1,seat2;
	cin>>car1>>seat1>>car2>>seat2;
	if(car1==car2&&seat1==seat2){
		cout<<"0000"<<endl;
		return 0;
	}
	bool pass1=false,pass2=false,pass3=false,pass4=false;
	if(car1==car2) pass1=true;
	char seat1_first=seat1[0];
	char seat1_second=seat1[1];
	char seat2_first=seat2[0];
	char seat2_second=seat2[1];
	char seat1_char=seat1[2];
	char seat2_char=seat2[2];
	if(seat1_first==seat2_first&&seat1_second==seat2_second&&pass1) pass2=true;
	if(seat1_char=='A'||seat1_char=='B'||seat1_char=='C'){
		if((seat2_char=='A'||seat2_char=='B'||seat2_char=='C')&&seat1_char!=seat2_char&&pass2){
			pass3=true;
		}
	}
	if(seat1_char=='D'||seat1_char=='E'){
		if((seat2_char=='D'||seat2_char=='E')&&seat1_char!=seat2_char&&pass2){
			pass3=true;
		}
	}
	if(seat1_char=='A'&&seat2_char=='B'){
		if(pass2) pass4=true;
	}
	if(seat1_char=='B'&&(seat2_char=='A'||seat2_char=='C')){
		if(pass2) pass4=true;
	}
	if(seat1_char=='C'&&seat2_char=='B'){
		if(pass2) pass4=true;
	}
	if(seat1_char=='D'&&seat2_char=='E'){
		if(pass2) pass4=true;
	}
	if(seat1_char=='E'&&seat2_char=='D'){
		if(pass2) pass4=true;
	}
	cout<<pass1<<pass2<<pass3<<pass4<<endl;
	return 0;
}
