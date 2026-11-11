//GZ-J00021 贵阳市第一中学  郑淇予
#include<bits/stdc++.h>
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
		return 0;
	}
	if(s1[0] != s1[0] || s1[1] != s2[1]){
		cout << "1000";
		return 0;
	}
	int p1 = s1[2]-'A', p2 = s2[2]-'A';
	if((p1 <= 2 && p2 >= 3) || (p1 >= 3 && p2 <= 2)){
		cout << "1100";
		return 0;
	}
	if(p1 == 3)p1++;
	if(p2 == 3)p1++;
	cout << "111";
	if(abs(p1-p2) == 1){
		cout << "1"; 
	}
	else{
		cout << "0";
	}
	return 0;
}
