#include<bits/stdc++.h>
using namespace std;
string c1 , w1 , c2 , w2;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> w1 >> c2 >> w2;
	if (c1 != c2){
		cout << "0000";
		return 0;
	}
	if (w1[0] != w2[0] || w1[1] != w2[1]){
		cout << "1000";
		return 0;
	}
	if (((w1[2] - 'A') / 3) != ((w2[2] - 'A') / 3)){
		cout << "1100";
		return 0;
	}
	if (abs(w1[2] - w2[2]) != 1){
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
} 
