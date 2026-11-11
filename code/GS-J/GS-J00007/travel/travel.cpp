#include <bits/stdc++.h>
using namespace std;

int main()
{
	frepon("travel.in","r",stdin);
	frepon("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(s1[0]==s2[0])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}	
	return 0;	
}
