#include <iostream>
#include <cstring>
using namespace std;
bool seat_or_seat(char a,char b){
	int c,d;
	if(a == 'A' || a == 'B' || a == 'C'){
		c = 1;
	}else{
		c = 2;
	}if(b == 'A' || b == 'B' || b == 'C'){
		d = 1;
	}else{
		d = 2;
	}if(c == d) return 1;
	return 0;
}
bool seat_nextto(char a,char b){
	if(a - b == 1 || a - b == -1){
		return 1;
	}return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string car_1,car_2,seat_1,seat_2;
	cin >> car_1 >> seat_1 >> car_2 >> seat_2;
	if(car_1 == car_2){
		cout << 1;
		string h_1 = seat_1.substr(0,2),h_2 = seat_2.substr(0,2);
		char seat__1 = seat_1[2],seat__2 = seat_2[2];
		if(h_1 == h_2){
			cout << 1;
			if(seat_or_seat(seat__1,seat__2)){
				cout << 1;
				if(seat_nextto(seat__1,seat__2)){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
			cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
