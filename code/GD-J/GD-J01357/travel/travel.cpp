#include<bits/stdc++.h>
using namespace std;
#define LL long long

string c1, s1, c2, s2;
map<int, char> a;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	bool bk1, bk2, bk3, bk4;
	bk1 = bk2 = bk3 = bk4 = false;
	if(c1 == c2){
		cout << "1";
		bk1 = true;
	}
	else cout << "0";
	if(bk1 && s1[0] == s2[0] && s1[1] == s2[1]){
		cout << "1";
		bk2 = true;
	}
	else cout << "0";
	if(s1[2] < s2[2]) swap(s1[2], s2[2]);
	if(bk1 && bk2 && ((s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'C' && s2[2] == 'A') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'F' && s2[2] == 'D'))){
		cout << "1";
		bk3 = true;
	}
	else cout << "0";
	if(bk1 && bk2 && bk3 && (s1[2] - s2[2] == 1)) cout << "1";
	else cout << "0";
	return 0;
}
