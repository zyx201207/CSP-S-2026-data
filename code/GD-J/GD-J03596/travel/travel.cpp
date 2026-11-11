#include<bits/stdc++.h>
using namespace std;
int coach1,coach2;
string seat1,seat2;
int main(){
	cin>>coach1>>seat1>>coach2>>seat2;
	if(coach1==coach2){
		cout<<"1";
		if((seat1[0]-'0')*10+(seat1[1]-'0')==(seat2[0]-'0')*10+(seat2[1]-'0')){
			cout<<"1";
			if(seat1[2]=='A'||seat1[2]=='B'||seat1[2]=='C'){
				if(seat2[2]=='A'||seat2[2]=='B'||seat2[2]=='C'){
					cout<<"1";
					if(abs(seat2[2]-seat1[2])==1){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					cout<<"00";
				}
			}else{
				if(seat2[2]=='D'||seat2[2]=='F'){
					cout<<"1";
					if(abs(seat2[2]-seat1[2])==1){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0; 
}
