#include <bits\stdc++.h>
using namespace std;
int main(){
	freopen("travel1.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==s1){
		cout << 1;
		int r, x;
		r = (s1[0]-'0')*10 + (s1[1]-'0'); 
		x = (s2[0]-'0')*10 + (s2[1]-'0');
		if(r==x){
			cout << "1";
			if(s1[2] <= 'C' && s2[2] <= 'C'){
				cout << "1";
				if(abs(s1[2]-s2[2]) == 1){
					cout << "1"; 
				}else{
					cout << "0";
				}
			}else if(s1[2] >= 'D' && s2[2] >= 'D'){
				cout << "11";
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}


	return 0;
}
