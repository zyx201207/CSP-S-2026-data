#include <bits/stdc++.h>
using namespace std;

string train1, seat1, train2, seat2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> train1 >> seat1 >> train2 >> seat2;
	if(train1 == train2)  cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	
	if(seat1[0] == seat2[0] && seat1[1] == seat2[1])  cout << 1;
	else{
		cout << "000";
		return 0;
	}
	
	if((seat1[2] - 'C' <= 0 && seat2[2] - 'C' > 0) || (seat1[2] - 'C' > 0 && seat2[2] - 'C' <= 0)){
		cout << "00";
		return 0;
	}else  cout << 1;
	
	if(abs(seat1[2] - seat2[2]) == 1)  cout << 1;
	else cout << 0;
	
	return 0;
} 
