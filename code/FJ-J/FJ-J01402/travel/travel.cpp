#include <iostream>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a1, a2, b1, b2;
	char a3, b3;
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
	if (a1 == b1){
		cout << 1;
		if (a2 == b2){
			cout << 1;
			
			int flag = 0;
			if ((a3 == 'D') || (a3 == 'F')){
				if ((b3 == 'D') || (b3 == 'F'))
					flag = 1;
			}else{
				if (!((b3 == 'D') || (b3 == 'F')))
					flag = 1;
			}
			cout << flag;
			
			if (flag && (abs((a3 - 'A') - (b3 - 'A')) == 1))
				cout << 1;
				
			else cout << 0;
		}else cout << "000";
	}else cout << "0000";
} 
