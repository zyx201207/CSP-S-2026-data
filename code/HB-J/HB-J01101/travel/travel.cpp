#include<bits/stdc++.h>
using namespace std;

int c1,c2,a1,a2;
string s1,s2;
char x,y;

bool check1(char x, char y)
{
	if(x == 'A' or x == 'B' or x == 'C'){
		if(y == 'A' or y == 'B' or y == 'C'){
			return 1;
		}
	}
	else if(x == 'D' or x == 'F'){
		if(y == 'D' or y == 'F'){
			return 1;
		}
	}
	return 0;
}
bool check2(char x, char y)
{
	if(x == 'A' and y == 'B') return 1;
	if(x == 'B' and y == 'C') return 1;
	if(x == 'B' and y == 'A') return 1;
	if(x == 'C' and y == 'B') return 1;
	if(x == 'D' and y == 'F') return 1;
	if(x == 'F' and y == 'D') return 1;
	return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	a1 = (s1[0] - '0')*10 + (s1[1] - '0');
	a2 = (s2[0] - '0')*10 + (s2[1] - '0');
	x = s1[2];
	y = s2[2];
	
	if(c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	else
	{
		if(a1 != a2)
		{
			cout << 1000;
			return 0;
		}
		else
		{
			if(!check1(x,y))
			{
				cout << 1100;
				return 0;
			}
			else
			{
				if(!check2(x,y))
				{
					cout << 1110;
					return 0;
				}
			}
		}
	}
	
	cout << 1111;
	return 0;
}
