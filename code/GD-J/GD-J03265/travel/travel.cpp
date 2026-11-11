// /travel/travel.cpp

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string c1, s1, c2, s2;

bool sameSide(char a, char b){
	if (a <= 'C' && b <= 'C') return true;
	if (a >= 'D' && b >= 'D') return true;
	return false;
}

bool near(char a, char b){
	if (abs(a-b) == 1) return true;
	return false;
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	// 同一节车厢
	bool same_train = (c1 == c2);
	
	// 同一排
	bool same_col = ((s1[0] == s2[0]) && (s1[1] == s2[1])) && same_train;
	
	// 同一侧
	bool same_side = sameSide(s1[2], s2[2]) && same_col && same_train;
	
	// 相邻
	bool together = same_train && same_col && same_side && near(s1[2], s2[2]) && same_train;
	
	cout << same_train << same_col  << same_side << together; 
	return 0;
} 
