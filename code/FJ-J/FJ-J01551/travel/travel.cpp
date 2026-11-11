#include <bits/stdc++.h>
using namespace std;
int zgy_a,zgy_b;
string zgy_s1,zgy_s2;
int main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> zgy_a >> zgy_s1 >> zgy_b >> zgy_s2;
	if(zgy_a == zgy_b)
	{
		cout << "1";
	}
	else
	{
		cout << "0000";
		return 0;
	}
	
	int zgy_q = 0;
	int zgy_w = 0;
	
	zgy_q = (zgy_s1[0] - '0') * 10 + (zgy_s1[1] - '0');
	zgy_w = (zgy_s2[0] - '0') * 10 + (zgy_s2[1] - '0');
	
	if(zgy_q == zgy_w)
	{
		cout << "1";
	}
	else
	{
		cout << "000";
		return 0;
	}
	
	int zgy_e = 0,zgy_r = 0;
	zgy_e = zgy_s1[2] - '0';
	zgy_r = zgy_s2[2] - '0';
	
	if(zgy_e > 19 && zgy_r > 19 || zgy_e <= 19 && zgy_r <= 19)
	{
		cout << "1";
	}
	else
	{
		cout << "00";
		return 0;
	}
	
	if(abs(zgy_e - zgy_r) == 1 || zgy_e >= 20 && zgy_r >= 20)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	
	return 0;
}
