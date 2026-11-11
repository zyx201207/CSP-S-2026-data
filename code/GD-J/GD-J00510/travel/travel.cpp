#include <bits/stdc++.h>
using namespace std;
string C1,S1,C2,S2;
string b[4] = {"AB","BC","DF"};
bool aa = false,bb = false,cc = false,c = false,d = false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> C1 >> S1 >> C2 >> S2;
	string left = "ABC";
	string right = "DF";
	if ((C1[0] == C2[0]) && (C1[1] == C2[1]))
	{
		cout << "1";
		aa = true;
	}
	else
	{
		cout << "0";
	}
	if (((S1[0] == S2[0]) && (S1[1] == S2[1])) && (aa))
	{
		cout << "1";
		bb = true;
	}
	else
	{
		cout << "0";
	}
	if ((left.find(S1[2]) != -1) && (left.find(S2[2]) != -1))
	{
		c = true;
	}
	if ((right.find(S1[2]) != -1) && (right.find(S2[2]) != -1))
	{
		c = true;
	}
	if ((c) && ((aa) && bb))
	{
		cout << "1";
		cc = true;
	}
	else
	{
		cout << "0";
	}
	string s1(1,S1[2]),s2(1,S2[2]);
	string h = s1 + s2;
	for (auto v : b)
	{
		if (v == h)
		{
			d = true;
			break;
		}
	}
	if (((aa) && (bb) && (cc)) && (d))
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	return 0;
} 
