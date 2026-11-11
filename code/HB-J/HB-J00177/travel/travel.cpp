#include <bits/stdc++.h>
using namespace std;

int num1,num2,line1,line2;
char idx1,idx2;
string seat1,seat2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> num1 >> seat1 >> num2 >> seat2;
	line1 = (seat1[0] - '0') * 10 + (seat1[1] - '0');
	line2 = (seat2[0] - '0') * 10 + (seat2[1] - '0');
	idx1 = seat1[2] - 'A' + 1,idx2 = seat2[2] - 'A' + 1;
	if(num1 == num2){
		if(line1 == line2){
			if((idx1 <= 3 && idx2 <= 3) || (idx1 >= 4 && idx2 >= 4)){
				if(abs(idx1 - idx2) == 1){
					cout << "1111\n";
				}else cout << "1110\n";
			}else cout << "1100\n";
		}else cout << "1000\n";
	}else cout << "0000\n";

	return 0;
}
