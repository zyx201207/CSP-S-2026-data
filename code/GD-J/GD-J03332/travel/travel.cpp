#include<bits/stdc++.h> 
using namespace std;
const int N = 3;

string x , y , a , b;
char num[6] = {'A' , 'B' , 'C'};

int main(){
	freopen("travel.in" , "r" , stdin); 
	freopen("travel.out" , "w" , stdout);
	cin >> x >> y >> a >> b;
	if (x == a){
		cout << "1";
		if (y[0] == b[0] && y[1] == b[1]){
			cout << 1;
			int r = 0 , x = 0;
			string r1 , x1;
			for (int i = 0 ; i < 3 ; i++){
				if (y[2] == num[i]){
					r += 1;
					r1 = num[i];
				} 
				if (b[2] == num[i]){
					x += 1;
					x1 = num[i];
				}
			}
			if (r == x){
				cout << "1";
				if (r == 0 && x == 0) cout << "1";
				else if (r == 1){
					if (r1 == "A" && x1 == "C" || r1 == "C" && x1 == "A") cout << 0;
					else cout << "1";
				}
			}else{
				cout << "00";
			}
		} else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
