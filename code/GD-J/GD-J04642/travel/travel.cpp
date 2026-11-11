#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
#define LL long long
const int N = 1e5 + 10;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin >> a1 >> a2 >> b1 >> b2;
	if(a1 == b1)
	{
		cout << 1;
		if(a2[0] == b2[0] && a2[1] == b2[1])
		{
			cout << 1;
			if(a2[2] >= 'A' && a2[2] <= 'C' && b2[2] >= 'A' && b2[2] <= 'C')
			{
				cout << 1;
				if(abs(a2[2] - b2[2]) == 1)
					cout << 1 << endl;
				else
					cout << 0 << endl;
			}
			else if((a2[2] == 'D' || a2[2] == 'E') && (b2[2] =='D' || b2[2] == 'E'))
			{
				cout << "1";
			}
			else
				cout << "00" << endl;
		}
		else
			cout << "000" << endl;
	}
	else
		cout << "0000" << endl;
	return 0;
}

