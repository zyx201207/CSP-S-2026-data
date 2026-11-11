#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int cx_1, cx_2;
	string seat_1, seat_2;
	cin >> cx_1 >> seat_1 >> cx_2 >> seat_2;
	if(cx_1 == cx_2)
	{
		cout << "1";
		if(seat_1[0] == seat_2[0] && seat_1[1] == seat_2[1])
		{
			cout << "1";
			if(seat_1[2] == 'A')
			{
				if(seat_2[2] == 'B')
				{
					cout << "11";
				}
				else if(seat_2[2] == 'D' || seat_2[2] == 'F')
				{
					cout << "00";
				}
				else
				{
					cout << "10";
				}
			}
			else if(seat_1[2] == 'B')
			{
				if(seat_2[2] == 'A' || seat_2[2] == 'C')
				{
					cout << "11";
				}
				else if(seat_2[2] == 'D' || seat_2[2] == 'F')
				{
					cout << "00";
				}
			}
			else if(seat_1[2] == 'C')
			{
				 if(seat_2[2] == 'A')
				{
					cout <<"10";
				}
				else if(seat_2[2] == 'B')
				{
					cout << "11";
				}
				else if(seat_2[2] == 'D' || seat_2[2] == 'F')
				{
					cout <<"00";
				}
			}
			else if(seat_1[2] == 'D')
			{
				if(seat_2[2] == 'F')
				{
					cout << "11";
				}
				else
				{
					cout << "00";
				}
			}
			else if(seat_1[2] == 'F')
			{
				if(seat_2[2] == 'D')
				{
					cout << "11";
				}
				else
				{
					cout << "00";
				}
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
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
