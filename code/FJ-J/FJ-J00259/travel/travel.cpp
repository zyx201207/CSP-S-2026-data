#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000" << endl;
		return 0;
	}else{
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << "1";
			char r = s1[2], x = s2[2];
			int a = (int)(r - 'A'), b = (int)(x - 'A');
			if(r == 'D') a++;
			if(x == 'D') b++;
			if((a <= 2 && b <= 2) || (a >= 4 && b >= 4)){
				cout << "1";
				if(a - b == 1 || a - b == -1){
					cout << "1";
					return 0;
				}else{
					cout << "0";
					return 0;
				}
			}else{
				cout << "00";
				return 0;
			}
		}else{
			cout << "000";
			return 0;
		}
	}
	return 0;
}
