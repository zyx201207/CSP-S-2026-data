//六盘水市第二十四中学 廖奕然 GZ-J00598 
#include <bits/stdc++.h>
using namespace std;
struct Seat{
	string cx;
	string seat;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	Seat r,x;
	cin >> r.cx >> r.seat >> x.cx >> x.seat;
	if(r.cx != x.cx){
		cout << "0000";
		return 0;
	}
	for(int i = 0;i < r.seat.size() - 1;i++){
		if(r.seat[i] != x.seat[i]){
			cout << "1000";
			return 0;
		}
	}
	if((r.seat[2] <= 'C' && x.seat[2] > 'C') || r.seat[2] > 'C' && x.seat[2] <= 'C'){
		cout << "1100";
	}
	if(abs(r.seat[2] - x.seat[2]) == 1){
		cout << "1111";
	}else{
		cout << "1110";
	}
	return 0;
}
