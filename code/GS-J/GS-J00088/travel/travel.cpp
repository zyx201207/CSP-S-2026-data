#include <bits/stdc++.h>
using namespace std;

int main()
{
	peropen("travel.in","r",std);
	preopen("trevel.out","w",std);
	string C1,S1,C2,S2;
	cin >> C1 >> S1 >> C2 >> S2;
	if(C1==S2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(C2%100&&C2%10==S2%100&&S2%10)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(C2/10==S2/10)
	{
		cout << 1;
	}
	else
	{
		cout 0;
	}
	if(C2/10=='A'&&S2/10=='B'||C2/10=='B'&&S2/10=='A'||C2/10=='B'&&S2/10=='C'||C2/10=='C'&&S2/10=='B'||C2/10=='D'&&S2/10=='F'||C2/10=='F'&&S2/10=='D')
	{
		cout << 1;
	}
	else
	{
		cout 0;
	}
	return 0;
	
}
