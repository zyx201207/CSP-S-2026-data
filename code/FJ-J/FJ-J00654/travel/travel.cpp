#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
string r_seat_pai,x_seat_pai;
struct seat{
	int box;
	string seat_information;
}; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	seat r,x;
	cin >> r.box >> r.seat_information >> x.box >> x.seat_information;
	if(r.box == x.box){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	for(int i = 0;i<2;i++){
		r_seat_pai+=r.seat_information[i];
		x_seat_pai+=x.seat_information[i];
	}
	if(r_seat_pai == x_seat_pai){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	if(r.seat_information[2]<='C'){
		if(x.seat_information[2]<='C'){
			cout << "1";
		}else{
			cout << "00";
			return 0;
		}
		if(r.seat_information[2] == x.seat_information[2]+1 || r.seat_information[2]+1 == x.seat_information[2]){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	if(r.seat_information[2]>'C'){
		if(x.seat_information[2]>'C'){
			cout << "1";
		}else{
			cout << "00";
			return 0;
		}
		if((r.seat_information[2] == 'D' && x.seat_information[2] == 'E') || (r.seat_information[2] == 'E' && x.seat_information[2] == 'D')){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
