#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	bool flag = 1;
	string s1, s2, s3, s4;
	
	cin >> s1 >> s2 >> s3 >> s4;
	
	int na = stoi(s1), nb = stoi(s3);
	flag &= (na == nb);
	cout << flag;
	
	int ra = stoi(s2.substr(0, 2)), rb = stoi(s4.substr(0, 2));
	flag &= (ra == rb);
	cout << flag;
	
	char ca = s2[2], cb = s4[2];
	flag &= ((ca <= 'C' && cb <= 'C') || (ca > 'C' && cb > 'C'));
	cout << flag;
	
	flag &= (ca - 1 == cb || ca + 1 == cb);
	cout << flag;
	
	return 0;
}