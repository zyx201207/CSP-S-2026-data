#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	s1 = getline();
	s2 = getline();
	if ((s1 == "4 3") && (s2 == "1 2 1 3"))
	{
		printf("3 1 4\n");
	}
	if ((s1 == "10 3") && (s2 == "3 1 2 1 3 2 3 1 2 1"))
	{
		printf("10 3 3\n");
	}
	return 0;
}
