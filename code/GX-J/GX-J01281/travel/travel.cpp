#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w"stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(s1 == s2)
	{
		cout << 1;
		if(s2[0] == c2[0] && s2[1] == c2[1])
		{
			cout << 1;
			if((s2[2] == 'A' && (c2[2] == 'B' || s2[2] == 'C')) || (s2[2] == 'B' && (c2[2] == 'A' || s2[2] == 'C')) || (s2[2] == 'C' && (c2[2] == 'A' || s2[2] == 'B')));
			{	
				cout << 1;
				if((s2[2] == 'B' && (c2[2] == 'C' || s2[2] == 'A')) || (s2[2] == 'A' && (c2[2] == 'C' || s2[2] == 'B')) || (s2[2] == 'C' && (c2[2] == 'B' || s2[2] == 'A')));
				{
					cout << 1;
					if(s1 != s2)
					{
						cout << 0;
					}
				} 
			}
		}		
	}
	cout << 0;
	return 0;
}
