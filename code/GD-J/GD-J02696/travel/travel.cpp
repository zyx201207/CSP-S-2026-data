#include <bits/stdc++.h>
using namespace std;

string box1, box2, str1, str2;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);	
	cin >> box1 >> str1 >> box2 >> str2;
	char c1 = str1[2], c2 = str2[2];
	//~ cout << c1 << c2 << endl;
	if(box1 != box2)
	{
		printf("0000\n");
	}
	else if(str1.substr(0, 2) != str2.substr(0, 2))
	{
		printf("1000\n");
	}
	else if(abs(c1 - c2) > 1)
	{
		if((c1 <= 'C' && c2 <= 'C') || (c1 > 'C' && c2 > 'C'))
		{
			printf("1110\n");
		}
		else 
		{
			printf("1100\n");
		}
	}
	else if((c1 == 'C' && c2 == 'D') || (c1 == 'D' && c2 == 'C'))
	{
		printf("1100\n");
	}
	else
	{
		printf("1111\n");
	}
	return 0;
}

