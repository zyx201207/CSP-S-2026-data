#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin)
    freopen("travel.out","w",stdout)
    string a,b,c,d;
    int x,y;
    cin >> a >> b >> c >> d;
    x = b[2] - '0';
    y = d[2] - '0';
    if(a == c)
    {
        cout << "1";
        if(b[0] == d[0] && b[1] == d[1])
        {
            cout << "1";
            if(x + y == 44 || (x + y <= 37 && x - y < 2 && x - y > -2))
            {
				cout << "1";
				if(x - y == 1 || y - x == 1)
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
