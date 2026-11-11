#include<bits/stdc++.h>
using namespace std;
string num1,seat1,num2,seat2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>num1>>seat1>>num2>>seat2;
	if(num1==num2){
		if(seat1[1]-'0'==seat2[1]-'0' and seat1[0]-'0'==seat2[0]-'0'){
			if(seat1[2]-'0'<20&&seat2[2]-'0'<20){
				if((seat1[2]+1==seat2[2])or(seat1[2]-1==seat2[2])){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else if(seat1[2]-'0'>=20 and seat2[2]-'0'>=20){
				cout<<"1111";
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
 	}
	return 0;
}

