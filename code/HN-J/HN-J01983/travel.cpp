#include <iostream>
using namespace std;
long long r,rz,x,xz,sum;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int sum;
	cin >> r >> rz >> x >> xz;
	if(r == x)
	{
		cout << "1";
		if(sum > 0)
		{
			cout << "100";
		}
		else if(sum < 0)
		{
			cout << "110";
		}
		else
		{
			cout << "111";
		}
	}
	else if(r != x)
	{
		cout << "0000";
	}
	return 0; 
} 
