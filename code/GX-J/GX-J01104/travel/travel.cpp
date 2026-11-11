#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    getline(cin , s);
    string a = "";
    string b = "";
    for(int i = 0 ; i < s.size() ; i++)
    {
        int c;
        if(s[i] == ' ')
        {
            c++;
            continue;
        }
        if(c == 3) break;
        a += s[i];
    }
    for(int i = 0 ; i < s.size() ; i++)
    {
        int c;
        if(s[i] == ' ')
        {
            c++;
            continue;
        }
        if(c == 3) break;
        b += s[i];
    }
    for(int i = 0 ; i < a.size(); i++)
    {
        if(a[0] == b[0] && a[1] == b[1])
        {
            cout << 1;
            if(a[2] == b[2] && a[3] == a[3])
            {
                cout << 1;
                if(a[4] >= 'A' && a[4] <= 'C' && b[4] >= 'A' && b[4] <= 'C')
                {
                    cout << 1;
                    if(a[4] - 1 == b[4] || a[4] + 1 == b[4]) cout << 1;
                    else
                    {
                        cout << 0;
                        break;
                    }
                }
                else if(a[4] >= 'D' && a[4] <= 'F')
                {
                    cout << 1;
                    if(a[4] - 1 == b[4] || a[4] + 1 == b[4]) cout << 1;
                    else
                    {
                        cout << 0;
                        break;
                    }
                }
                else
                {
                    cout << 0 << 0;
                    break;
                }
            }
            else
            {
                cout << 0 << 0 << 0;
                break;
            }
        }
        else
        {
            cout << 0 << 0 << 0 << 0;
            break;
        }

    }
    return 0;
}
