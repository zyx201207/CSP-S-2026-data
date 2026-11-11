#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    int ch1 = stoi(s1),ch2 = stoi(s2);
    char w1 = s1[2], w2 = s2[2];
    if (c1 == c2)
    {
        cout << 1;
        if (ch1 == ch2)
        {
            cout<<"1";
            if ((w1 == 'A' || w1 == 'B' || w1 == 'C') && (w2 == 'A' || w2 == 'B' || w2 == 'C'))
            {
                cout<<"1";
                if ((w1 == 'A' && w2 == 'B') || (w1 == 'B' && w2 == 'C'))
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
            }
            else if ((w1 == 'D' || w1 == 'F') && (w2 == 'D' || w2 == 'F'))
            {
                cout<<"11";
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
