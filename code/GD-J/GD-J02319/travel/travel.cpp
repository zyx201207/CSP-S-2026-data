#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	bool op = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << 1;
		op = 1;
	}
	else
	{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}

	int s = (s1[0]-'0')*10+(s1[1]-'0'),ss = (s2[0]-'0')*10+(s2[1]-'0');
	if(s == ss)
	{
		cout << 1;
		op = 1;
	}
	else{
		op =0;
		cout << 0 << 0 << 0;
		return 0;
		
	}


	s = s1[2]-'A'+1;
	//cout << s1[2];
	ss = s2[2] - 'A'+1;
	//cout << s2[2];
	if(s <= 3 && ss <= 3)
	{
		cout << 1;
		op = 1;
		//cout  << " "<< s  << " "<< ss << "";
		if(s+1 == ss || s-1 == ss)
		{
			cout << 1;
			
		}
		else
		{
			cout << 0;
		}
	}
	else if(s >= 4 && ss >= 4)
	{
		cout << 1;
		op=1;
		if(s+1 == ss || s-1 == ss)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << 0;
		op =0;
		cout << 0;
	}
	return 0;
}
