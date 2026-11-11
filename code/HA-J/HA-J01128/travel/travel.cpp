#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	int a1=0, a2=0, a3=0, a4=0;
	if (c1 == c2)
	{
		a1=1;
		int cnt=0;
		for (int i=0;i<2;i++)
		{
			if (s1[i] == s2[i]) cnt++;
		}
		if (cnt==2)
		{
			a2=1;
			if (s1[2]<='C' && s2[2]<='C' || s1[2]>='D' && s2[2]>='D')
			{
				a3=1;
				if (abs(s1[2]-s2[2]) == 1) a4=1;
			}
		}
	}
	cout << a1 << a2 << a3 << a4;
	
	return 0;
}
