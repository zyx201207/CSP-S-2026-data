#include<bits/stdc++.h>

using namespace std;
string bx_r, st_r, bx_x, st_x;
int side[6] = {1, 1, 1, 2, -1, 2};
bool check1(char a, char b)
{
	if(side[a-'A']==side[b-'A'])
	{
		return true;
	}
	return false;
}
bool check2(char a, char b)
{
	if(a+1==b||b+1==a)
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> bx_r >> st_r >> bx_x >> st_x;
	if(bx_r==bx_x)
	{
		cout << "1";
		if(st_r.substr(0, 2)==st_x.substr(0, 2))
		{
			cout << "1";
			if(check1(st_r[2], st_x[2]))
			{
				cout << "1";
				if(check2(st_r[2], st_x[2]))
				{
					cout << "1";
				}
				else
				{
					cout << "0";
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	
	return 0;
}
