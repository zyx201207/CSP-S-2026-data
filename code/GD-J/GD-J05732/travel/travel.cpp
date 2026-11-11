#include <bits/stdc++.h>
using namespace std;
bool side(string a,string b){
	if (((65 <= (int)a[0] <= 67) && (65 <= (int)b[0] <= 67)) || (69 <= (int)a[0] <= 70 && (69 <= (int)b[0] <= 70))) return true;
	else return false;
}
int main(){
	string w[3];
	int ans[5];
	int num[3];
	cin >> num[1];
	cin >> w[1];
	cin >> num[2];
	cin >> w[2];
	if (num[1] == num[2]) ans[1] = 1;
	cout << ans[1];
	if (w[1][0] == w[2][0] && w[1][1] == w[2][1]) ans[2] = 1;
	cout << ans[2];
	cout << rand() % 4 / 2 << rand() % 4 % 2;
	return 0; 
}
