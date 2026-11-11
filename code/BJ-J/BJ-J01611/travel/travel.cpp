#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int a, c;
	char b[8], d[8];
	
	cin >> a >> b >> c >> d;
	
	if (a == c)
	{
		cout << '1';
		
		if (b[0] == d[0] && b[1] == d[1])
		{
			cout << '1';
			
			bool x, y;
			x = (b[2] <= 'C');
			y = (d[2] <= 'C');
			
			if (x == y)
			{
				cout << '1';
				
				int m, n;
				
				m = (b[2] != 'F' ? b[2] - 'A' : b[2] - 'A' - 1);
				n = (d[2] != 'F' ? d[2] - 'A' : d[2] - 'A' - 1);
				
				cout << (m - n == 1 || n - m == 1) << '\n';
			}
			else cout << "00\n";
		}
		else cout << "000\n";
	}
	else cout << "0000\n";
	
	return 0;
}
