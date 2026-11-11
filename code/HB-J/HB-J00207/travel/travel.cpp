#include <bits/stdc++.h>
using namespace std;
bool check(string s1, string s2)
{
    if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
    {
        if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
        {
            return true;
        }
        return false;
    }
    else
    {
        if (s2[2] == 'D' || s2[2] == 'F')
        {
            return true;
        }
        return false;
    }
}
bool cmp(string s1, string s2)
{
    int shu1 = stoi(s1.substr(0, 2));
    int shu2 = stoi(s2.substr(0, 2));
    if (shu1 == shu2)
    {
        if (s1[2] == 'A')
        {
            if (s2[2] == 'B') return true;
            else return false;
        }
        if (s1[2] == 'B')
        {
            if (s2[2] == 'A' || s2[2] == 'C') return true;
            else return false;
        }
        if (s1[2] == 'C')
        {
            if (s2[2] == 'B') return true;
            else return false;
        }
        if (s1[2] == 'D')
        {
            if (s2[2] == 'F') return true;
            else return false;
        }
        if (s1[2] == 'F')
        {
            if (s2[2] == 'D') return true;
            return false;
        }
    }
}
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
        cout << 1;
    else
    {
        cout << "0000" << endl;
        return 0;
    }
    bool flag = 0;
    if (s1.substr(0, 2) == s2.substr(0, 2))
    {
        cout << 1;
        flag = 1;
    }
    else
    {
        cout << 0;
    }
    if (flag && check(s1, s2))
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if (cmp(s1, s2))
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
