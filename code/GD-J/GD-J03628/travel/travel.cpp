#include <bits/stdc++.h>
using namespace std;
int x, y;
string a, b;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> a >> y >> b;
    if (x == y)
    {
        cout << "1";
	    if (a[0] == b[0] && a[1] == b[1])
	    {
	        cout << "1";
		    if (a[2] >= 'D' && b[2] >= 'D')
		    {
		        cout << "11";
		    }
		    else if (a[2] <= 'C' && b[2] <= 'C')
		    {
		        cout << "1";
		        if ((a[2] <= 'B' && b[2] <= 'B') || (a[2] >= 'B' && b[2] >= 'B'))
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
