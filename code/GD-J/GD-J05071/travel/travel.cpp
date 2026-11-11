#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout << 1;
			char s3 = s1[2];
			char s4 = s2[2];
			if((s3 == 'C' || s3 == 'A' || s3 == 'B') && (s4 == 'C' || s4 == 'A' || s4 == 'B') || (s3 == 'D' || s3 == 'F') && (s4 == 'D' || s4 == 'F'))
			{
				cout << 1;
				if(s3 == 'A' && s4 == 'C' || s4 == 'A' && s3 == 'C')
				{
					cout << 0;
				}
				else
				{
					cout << 1;
				}
			}
			else
			{
				cout << 0;
				cout << 0;
			}
		}
		else
		{
			cout << 0;
			cout << 0;
			cout << 0;
		}
	}
	else
	{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
