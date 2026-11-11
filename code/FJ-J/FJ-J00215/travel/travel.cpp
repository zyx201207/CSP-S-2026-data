#include<bits/stdc++.h>
using namespace std;

string a, b, aa, bb;

bool pan(int x, int y)
{
	if(x >= 'A' && x <= 'C' && y <= 'C' && y >= 'A')
	{
		return true;
	}
	else if(x >= 'D' && x <= 'F' && y <= 'F' && y >= 'D')
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> a >> b >> aa >> bb;
	
	if(a == aa) 
	{
		cout << "1";
		if(b[0] == bb[0] && b[1] == bb[1])
		{
			cout << "1";
			if(pan(b[2], bb[2]) == true)
			{
				cout << "1";
				if(abs(b[2] - bb[2]) == 1)
				{
					cout << 1;
					return 0;
				}
				else {
					cout << "0";
					return 0;
				}
			}
			else{
				cout << "00";
				return 0;
			}
		}
		else{
			cout << "000";
			return 0;
		}
	}
	else{
		cout << "0000"; 
		return 0;
	}
	
	
	
	
	
	return 0;
}
