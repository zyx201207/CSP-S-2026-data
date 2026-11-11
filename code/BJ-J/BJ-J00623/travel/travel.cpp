#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool is = true;
void printer()
{
    if (is)
    {
    	cout << 1;
    }
    else
    {
    	cout << 0;
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    for (int i = 0;i <= 1;i++)
    {
        is &= (c1[i] == c2[i]);
    }
    printer();
    for (int i = 0;i <= 1;i++)
    {
        is &= (s1[i] == s2[i]);
    }
    printer();
    if (!is)
    {
        cout << "00\n";
        return 0;
    }
    switch (s1[2])
    {
        case 'A':
        {
            if (s2[2] == 'B')
            {
                cout << "11";
            }
            else if (s2[2] == 'C')
            {
                cout << "10";
            }
            else
            {
                cout << "00";
            }
            break;
        }
        case 'B':
        {
            if ((s2[2] == 'A') || (s2[2] == 'C'))
            {
                cout << "11";
            }
            else
            {
                cout << "00";
            }
            break;
        }
        case 'C':
        {
            if (s2[2] == 'B')
            {
                cout << "11";
            }
            else if (s2[2] == 'A')
            {
                cout << "10";
            }
            else
            {
                cout << "00";
            }
            break;
        }
        case 'D':
        {
            if (s2[2] == 'F')
            {
                cout << "11";
            }
            else
            {
                cout << "00";
            }
            break;
        }
        case 'F':
        {
            if (s2[2] == 'D')
            {
                cout << "11";
            }
            else
            {
                cout << "00";
            }
            break;
        }
    }
    cout << '\n';
    return 0;
}
