#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b, c, d;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (a == c)
	{
		printf("1");
		if (b[0] == d[0] && b[1] == d[1])
		{
			printf("1");
			if ((b[2] < 'D' && d[2] < 'D') || (b[2] >= 'D' && d[2] >= 'D'))
			{
				printf("1");
				if (b[2] > d[2])
				{
					swap(b[2], d[2]);
				}
				if ((b[2] == 'A' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'C') || (b[2] == 'D' && d[2] == 'E'))
				{
					printf("1");
				}
				else
				{
					printf("0");
				}
			}
			else
			{
				printf("00");
			}
		}
		else
		{
			printf("000");
		}
	}
	else
	{
		printf("0000");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// done for 15min
