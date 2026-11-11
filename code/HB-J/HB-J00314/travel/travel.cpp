#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
bool flag2;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    long long xiang = (c1[0] - '0') * 10 + c1[1]- '0';
    long long xiang1 = (c2[0] - '0') * 10 + c2[1]- '0';
    if(xiang == xiang1)
    {
        cout << "1";
    }
    else
    {
        cout << "0000";
        flag2 = true;
        return 0;
    }
    long long pai1 = (s1[0] - '0') * 10 + s1[1] - '0';
    long long pai2 = (s2[0] - '0') * 10 + s2[1] - '0';
    if(pai1 == pai2 && flag2 == false)
    {
        cout << "1";
    }
    else
    {
        cout << "000";
        flag2 = true;
        return 0;
    }
    bool flag = false;
    if(s1[2] == 'F' && s2[2] == 'D' && flag2 == false)
    {
        cout << "1";
        flag = true;
    }
    else if(s1[2] == 'D' && s2[2] == 'F' && flag2 == false)
    {
        cout << "1";
        flag = true;
    }
    else if(s1[2] == 'C' && s2[2] == 'B' && flag2 == false)
    {
        cout << "1";
        flag = true;
    }
    else if(s1[2] == 'C' && s2[2] == 'A' && flag2 == false)
    {
        cout << "1";
        flag = true;
    }
    else if(s1[2] == 'B' && s2[2] == 'C' && flag2 == false)
    {
        cout << "1";
        flag = true;
    }
    else if(s1[2] == 'B' && s2[2] == 'A' && flag2 == false)
    {
        cout << "1";
        flag = true;
    }
    else if(s1[2] == 'A' && s2[2] == 'C' && flag2 == false)
    {
        cout << "1";
        flag = true;
    }
    else if(s1[2] == 'A' && s2[2] == 'B' && flag2 == false)
    {
        cout << "1";
        flag = true;
    }
    if(flag == false)
    {
        cout << "00";
        flag2 = true;
        return 0;
    }
    bool flag1 = false;
    if(s1[2] == 'D' && s2[2] == 'F' && flag2 == false)
    {
        cout << "1";
        flag1 = true;
    }
    else if(s1[2] == 'F' && s2[2] == 'D' && flag2 == false)
    {
        cout << "1";
        flag1 = true;
    }
    else if(s1[2] == 'C' && s2[2] == 'B' && flag2 == false)
    {
        cout << "1";
        flag1 = true;
    }
    else if(s1[2] == 'B' && s2[2] == 'C' && flag2 == false)
    {
        cout << "1";
        flag1 = true;
    }
    else if(s1[2] == 'B' && s2[2] == 'A' && flag2 == false)
    {
        cout << "1";
        flag1 = true;
    }
    else if(s1[2] == 'A' && s2[2] == 'B' && flag2 == false)
    {
        cout << "1";
        flag1 = true;
    }
    if(flag1 == false)
    {
        cout << "0" << "\n";
    }
    return 0;
}
