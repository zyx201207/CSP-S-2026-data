#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	{
		if(c1 == c2)
			cout << "1100";
		else
			cout << "0000";
		return 0;
	}
	{
		if(c1 == c2&&s1[10] - s2[10] <= 5||s2[10] - s1[10] <= 5)
			cout << "11";
		else
			cout << "000";
		return 0;
	}
	{
		if(c1 == c2&&s1[10] - s2[10] <= 2||s2[10] - s1[10] <= 2)
			cout << "111";
		else
			cout << "1100";
		return 0;
	}
	{
		if(c1 == c2&&s1[10] - s2[10] == 1||s2[10] - s1[10] == 1)
			cout << "1111";
		else
			cout << "1110";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
