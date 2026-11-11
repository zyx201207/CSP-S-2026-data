#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;	
	char a1 = s1[0],b1 = s1[1],d1 = s1[2];
	char a2 = s2[0],b2 = s2[1],d2 = s2[2];
	if(c1 == c2)
	{
		cout << "1";
		if(a1 == a2 && b1 == b2)
		{
			cout << "1";
			int wei1 = d1 - 'C';
			int wei2 = d2 - 'C';
			if((wei1 > 0 && wei2 >0) || (wei1 <= 0 && wei2 <= 0))
			{
				cout << "1";
				if(d1 - d2 == 1 || d1 - d2 == -1)
				{
					cout << "1";
				}
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
}
