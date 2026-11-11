#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);//²¹È« 
	int a,b;
	string aa,bb;
	cin >> a >> aa >> b >> bb;
	bool xx = 1;
	if(a == b)
	{
		cout << 1;
	}
	else
	{
		xx = 0;
		cout << 0;
	}
	bool xxx = 1;
	if(aa[0] ==bb[0] && aa[1] == bb[1] && xx)
	{
		cout << 1;
	}
	else
	{
		xxx = 0;
		cout << 0;
	}
	bool x = 1;
	if((aa[2] == 'A' ||aa[2] =='B' ||aa[2]=='C')&&(bb[2] == 'A' ||bb[2] =='B' ||bb[2]=='C')&&xx&&xxx)
	{
		cout << 1;
	}
	else if((aa[2] == 'D' ||aa[2] =='F')&&(bb[2] == 'D' ||bb[2] =='F' ))
	{
		cout << 1;
	}
	else
	{
		x = 0;
		cout << 0;
	}
	
	if((aa[2] - bb[2] == 1 || bb[2] - aa[2] == 1) && (x) && xx && xxx)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
