#include<bits/stdc++.h>
using namespace std;

int ck(string s1, string s2)
{
    if((s1[2] == 'A' or s1[2] == 'B' or s1[2] == 'C') and (s2[2] == 'D' or s2[2] == 'F'))
        return 0;
    if((s2[2] == 'A' or s2[2] == 'B' or s2[2] == 'C') and (s1[2] == 'D' or s1[2] == 'F'))
        return 0;
    return 1;
}

int check(char s1, char s2)
{
    // cout << s1 << " " << s2 << endl;
    if(s1 == 'A')
    {
        return s2 == 'B';
    }
    if(s1 == 'B')
    {
        return s2 == 'A' or s2 == 'C';
    }
    if(s1 == 'C')
    {
        return s2 == 'B';
    }
    if(s1 == 'D')
    {
        return s2 == 'F';
    }
    if(s1 == 'F')
    {
        return s2 == 'D';
    }
    return 0;
}

int main() {
    // travel
    freopen("travel.in", "r", stdin);
    // freopen("travel5.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string s[4];
    for(int i = 0; i < 4; i++) cin >> s[i];
    if(s[0] == s[2])
    {
        cout << "1";
        // cout << s[1][0] << " " << s[3][0] << " " << s[1][1] << " " << s[3][1] << endl;
        if(s[1][0] == s[3][0] and s[1][1] == s[3][1])
        {
            cout << "1";
            if(ck(s[1], s[3]))
            {
                cout << "1";
                if(check(s[1][2], s[3][2]))
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