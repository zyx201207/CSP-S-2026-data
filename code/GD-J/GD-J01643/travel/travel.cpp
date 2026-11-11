#include<iostream>
#include<string>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	bool is_same_room = (c1 == c2);
	cout << is_same_room;
	bool is_same_row = (s1.substr(0, 2) == s2.substr(0, 2));
	cout << (is_same_row && is_same_room);
	bool is_same_side = (s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C');
	cout << (is_same_side && is_same_row && is_same_room);
	bool is_beside = (s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1);
	cout << (is_beside && is_same_side && is_same_row && is_same_room);
	
	return 0;
} 
