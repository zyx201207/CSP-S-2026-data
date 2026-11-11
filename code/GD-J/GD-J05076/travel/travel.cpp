#include<bits/stdc++.h>

using namespace std;

int a1, a2, a3, a4;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) a1 = 1;
	
	int ts1, ts2;
	ts1 = (s1[0]- '0') * 10 + (s1[1] - '0');
	ts2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	if (a1 == 1 && ts1 == ts2) a2 = 1;
	
	int ss1, ss2;
	if(s1[2] >= 'A' && s1[2] <= 'C') ss1 = 1;
	else ss1 = 2;
	if(s2[2] >= 'A' && s2[2] <= 'C') ss2 = 1;
	else ss2 = 2;
	if (a2 == 1 && ss1 == ss2) a3 = 1;
	
	if (a3 == 1 && ((char(s1[2] + 1) == s2[2] || char(s1[2] - 1) == s2[2]) || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'))) a4 = 1;
	
	cout  << a1 << a2 << a3 << a4;
	
	
	return 0;
	
} 
