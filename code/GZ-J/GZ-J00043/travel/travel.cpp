//贵阳市第十九中学 刘承福 GZ-J00043
#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2, sit1, sit2;
bool flaga1, flaga2, flagb1, flagb2;
char a[5] = {'A', 'B', 'C'};
char b[5] = {'D', 'F', '#'};

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) cout << 1;
    else
	{
		cout << "0000" << endl;
		return 0;
	}
    sit1 += s1[0];
    sit1 += s1[1];
    sit2 += s2[0];
    sit2 += s2[1];
    if (sit1 == sit2) cout << 1;
    else
    {
    	cout << "000" << endl;
    	return 0;
	}
    for (int i = 0; i <= 2; i++)
    {
        if (s1[2] == a[i])
        {
            flaga1 = true;
        }
        if (s2[2] == a[i])
        {
            flaga2 = true;
        }
        if (s1[2] == b[i])
        {
            flagb1 = true;
        }
        if (s2[2] == b[i])
        {
            flagb2 = true;
        }
    }
    if ((flaga1 && flaga2) || (flagb1 && flagb2)) cout << 1;
    else
    {
    	cout << "00" << endl;
	}
    if (flaga1 && flaga2)
    {
        if ((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B'))
        {
            cout << 1;
        }
        else cout << 0;
    }
    else if (flagb1 && flagb2)
    {
        if ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'))
        {
            cout << 1;
        }
        else cout << 0;
    }
    else cout << 0;
    cout << endl;
    return 0;
}
