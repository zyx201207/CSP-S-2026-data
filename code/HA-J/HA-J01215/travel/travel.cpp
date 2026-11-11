#include <bits/stdc++.h>
using namespace std;
//good luck
int c1, c2; string s1, s2;
bool ans [4];

bool theSameSide (char a, char b)
{
	bool sidea, sideb; //1 -- 3; 0 -- 2
	if ('A' <= a && a <= 'C')
		sidea = 1;
	if ('A' <= b && b <= 'C')
		sideb = 1;
	return sidea == sideb;
}

int main ()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2)
		ans [0] = 1;
	
	if (ans [0] && s1 [0] == s2 [0] && s1 [1] == s2 [1])
		ans [1] = 1;
		
	if (ans [1] && theSameSide (s1 [2], s2 [2]))
		ans [2] = 1;
	
	if (s1 [2] > s2 [2])
		swap (s1, s2);
	if (ans [2] && (s2 [2] - s1 [2] == 1) || (s2 [2] == 'F'))
		ans [3] = 1;
	
	for (int i = 0; i < 4; ++ i)
		printf ("%d", ans [i]);
	return 0;
}
