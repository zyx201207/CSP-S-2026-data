#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string c1, s1, c2, s2;

bool che()
{
    if(c1 == c2)
    {
       return true;
    }
    else
    {
        return false;
    }
}

bool row()
{
    if(che() && s1[0] == s2[0] && s1[1] == s2[1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool side()
{
    if(che() && row())
    {
        if((s1[2] == 'A' && (s2[2] == 'B' || s2[2] == 'C')) || (s1[2] == 'B' && (s2[2] == 'A' || s2[2] == 'C')) || (s1[2] == 'C' && (s2[2] == 'A' || s2[2] == 'B'))  || (s1[2] == 'D' && s2[2] == 'F'));
        return true;
    }
    else
    {
        return false;
    }
}

bool seat()
{
    if(che() && row() && side() && (s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1 &&(s1[2] != 'C' && s2[2] != 'D')))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;


    if(che())
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if(row())
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if(side())
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if(seat())
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;

}
