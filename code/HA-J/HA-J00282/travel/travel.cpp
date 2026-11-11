#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1,s1,c2,s2;

	cin >> c1 >> s1 >> c2 >> s2;
	//小 R 的车票上的车厢号、座位号  小 X 的车票上的车厢号、座位号。
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	两张车票对应的座位是否在同一节车厢；
	if(c1[0] == c2[0] && c1[1] == c2[1]){
		cout << 1;
	//	两张车票对应的座位是否在同一节车厢的同一排；
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
		//	两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
			if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C'){
				cout << 1;
			//	两张车票对应的座位是否相邻
				if (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]){
					cout << 1;
				} 
				else cout << 0;
			
			}  
			else if (s1[2] >= 'D' && s2[2] >= 'D'&& s1[2] <= 'F' && s2[2] <= 'F' && s1[2] != 'E' && s2[2] != 'E'){
				cout << 1;
				if (s1[2] == 'D' && s2[2] == 'F'&& s1[2] == 'F' && s2[2] == 'D'){
					cout << 1;
				}
				else cout << 0;
	
			} 
			else cout << "00";
			
		} 
		else cout << "000";
		
	} 
	else cout << "0000";

	return 0;
} 
