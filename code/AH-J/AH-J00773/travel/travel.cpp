#include<bits/stdc++.h>
using namespace std;
int x, y, xx, yy;
char xxx, yyy;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> x >> xx >> xxx >> y >> yy >> yyy;
	//int xx = xxx[0] - '0' * 10 + xxx[1] - '0';
	//int yy = yyy[0] - '0' * 10 + yyy[1] - '0';
	if(x == y) cout << 1;
	else 
	{
		cout << "0000";
		return 0;
	}
	if(xx == yy) cout << 1;
	else 
	{
		cout << "000";
		return 0;
	}
	if(xxx >= 'A' && xxx <= 'C' && yyy >= 'A' && yyy <= 'C')
	{
		cout << 1;
		if(abs(xxx - yyy) == 1) cout << 1;
		else cout << 0;
		return 0;
	} 
	else if((xxx == 'F' && yyy == 'D') || (yyy == 'F' && xxx == 'D'))
	{
		cout << "11";
		return 0;
	}
	else cout << "00";
	return 0;
}
