#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
	{
		cout << "0000" <<endl;
	}else 
	{
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout << "1";
			if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
			{
				if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
			{
				cout << "1";
				if(abs(int(s1[2]) - int(s2[2])) == 1)
				{
					cout << "1" <<endl;
				}else
				{
					cout << "0" <<endl;
				}
			}else
				{
					cout << "00" <<endl;
				}
			}
			if(s1[2] == 'D' || s1[2] == 'F')
			{
				if(s2[2] == 'D' || s2[2] == 'F')
			{
				cout << "11" <<endl;
			}
			else
				{
					cout << "00" <<endl;
				}
			}
		}
		else
		{
			cout << "000" <<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
