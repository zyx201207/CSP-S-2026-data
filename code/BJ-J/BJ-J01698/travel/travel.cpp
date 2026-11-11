#include<bits/stdc++.h>
using namespace std;
string train1,seat1,train2,seat2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>> train1 >> seat1 >> train2 >> seat2;
	if(train1[0] == train2[0] && train1[1] == train2[1]){
		cout<< '1';
	}else{
		cout<< "0000";
		return 0;
	}//qustion1
	if(seat1[0] == seat2[0] && seat1[1] == seat2[1]){
		cout<< '1';
	}else{
		cout<< "000";
		return 0;
	}//question2
	int flag1 = false,flag2 = false;
	if(seat1[2] == 'A' || seat1[2] == 'B' || seat1[2] == 'C' ){
		flag1 = true;
	}
	if(seat2[2] == 'A' || seat2[2] == 'B' || seat2[2] == 'C' ){
		flag2 = true;
	}
	if(flag1 == flag2){
		cout<< '1';
	}else{
		cout<< "00";
		return 0;
	}//question3
	if((seat1[2] - seat2[2] == 1) || (seat1[2] - seat2[2] == -1)){
		cout<< '1';
	}else if((seat1[2] == 'D' && seat2[2] == 'F')||(seat1[2] == 'F' && seat2[2] == 'D')){
		cout<< '1';
	}else{
		cout<< '0';
	}//question4
	return 0;
}
