#include <iostream>

using std::cin;
using std::cout;

std::string s1, s2;

int c1, c2;

int my_abs(int num)
{
	return std::max(num, -num);
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> c1 >> s1 >> c2 >> s2;

	if(c1 != c2)
	{
		cout << "0000";

		return 0;
	}

	cout << "1";

	if(s1.substr(0, 2) != s2.substr(0, 2))
	{
		cout << "000";

		return 0;
	}

	cout << "1";

	if(s1[2] <= 'C' and s2[2] >= 'D')
	{
		cout << "00";

		return 0;
	}

	if(s2[2] <= 'C' and s1[2] >= 'D')
	{
		cout << "00";

		return 0;
	}

	cout << "1";

	if(my_abs(s2[2] - s1[2]) == 1)
	{
		cout << "1";

		return 0;
	}

	if(my_abs(s2[2] - s1[2]) == 2 and std::max(s1[2], s2[2]) == 'F')
	{
		cout << "1";

		return 0;
	}

	cout << "0";
}
