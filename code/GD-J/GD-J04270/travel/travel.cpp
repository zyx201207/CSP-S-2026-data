#include <bits/stdc++.h>
using namespace std;
int rp, xp; //排 
int rs, xs;
int rce, xce; //侧 
string rc, rz, xc, xz; //小r的车厢号，小r的座位号，小x的车厢号，小x的座位号 
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> rc >> rz >> xc >> xz;
	if (rc != xc)
	{
		cout << "0000";
		return 0;
	} 
	rp = (int(rz[0]) - '0') * 10 + int(rz[1]) - '0';
	xp = (int(xz[0]) - '0') * 10 + int(xz[1]) - '0';
	if (rp != xp)
	{
		cout << "1000";
		return 0;
	} 
	rs = int(rz[2]) - 'A', xs = int(xz[2]) - 'A';
	rce = (rs <= 2) ? 1 : 2;
	xce = (xs <= 2) ? 1 : 2;
	if (rce != xce)
	{
		cout << "1100";
		return 0;
	}
	if (rce == 1)
	{
		if (abs(rs - xs) > 1)
		{
			cout << "1110";
			return 0;
		}
		cout << "1111";
	}
	else
	{
		cout << "1111";
	}
	return 0;
}
