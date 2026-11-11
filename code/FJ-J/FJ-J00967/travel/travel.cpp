#include <iostream>
#include <string>
using namespace std;
string car1,seat1,car2,seat2;
bool flag1=1,flag2=1,flag3=1;
char onec,twoc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> car1 >> seat1 >> car2 >> seat2;
	int k = car1.length()-1;
	for(int i = 0;i <= k;i++){
		if(car1[i] != car2[i]){
			flag1 = 0;
			break;
		}
	}
	if(!flag1){
		cout << "0000";
		return 0;
	}
	if(seat1[0] == seat2[0] && seat1[1] == seat2[1]){
		flag2 = 1;
	}
	else{
		flag2 = 0;
	}
	if(!flag2){
		cout << "1000";
		return 0;
	}
	if(seat1[2] == 'A'||seat1[2] == 'B'||seat1[2] == 'C'){
		onec = 'L';
	}
	else{
		onec = 'R';
	}
	if(seat2[2] == 'A'||seat2[2] == 'B'||seat2[2] == 'C'){
		twoc = 'L';
	}
	else{
		twoc = 'R';
	}
	if(onec == twoc){
		flag3 = 1;
	}
	else{
		flag3 = 0;
		cout << "1100";
		return 0;
	}
	char x = seat1[2];
	char y = seat2[2];
	if((x == 'A' && y =='B')||(x == 'B'&&y == 'A')){
		cout <<"1111";
		return 0;
	}
	if((x == 'B'&&y == 'C')||(x == 'C'&&y == 'B')){
		cout << "1111";
		return 0;
	}
	if((x == 'D'&&y == 'F')||(x == 'F'&&y == 'D')){
		cout << "1111";
		return 0;
	}
	cout << "1110";
	return 0;
}

