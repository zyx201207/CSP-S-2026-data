#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1, s1, c2, s2;
char st1, st2;
int num1, num2;
map<char, int> mp;
map<pair<char, char>, bool> mp2;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) {
		cout << "0000";
		return 0;
	}
	for(int i = 0;i < s1.size();i++) {
		if(isdigit(s1[i])) {
			num1 = num1 * 10 + (int)(s1[i] - '0');
		} else {
			st1 = s1[i];
		}
	}
	for(int i = 0;i < s2.size();i++) {
		if(isdigit(s2[i])) {
			num2 = num2 * 10 + (int)(s2[i] - '0');
		} else {
			st2 = s2[i];
		}
	}
	if(num1 != num2) {
		cout << "1000";
		return 0;
	}
	mp['A'] = mp['B'] = mp['C'] = 1;
	mp['D'] = mp['F'] = 2;
	if(mp[st1] != mp[st2]) {
		cout << "1100";
		return 0;
	}
	mp2[{'A', 'B'}] = mp2[{'B', 'C'}] = mp2[{'D', 'F'}] = 1;
	if(mp2[{st1, st2}] == 1 || mp2[{st2, st1}] == 1) {
		cout << "1111";
		return 0;
	} else {
		cout << "1110";
		return 0;
	}
	return 0;
}
 
