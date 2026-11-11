#include <bits/stdc++.h>
using namespace std;

bool chk(string a, string b)
{
    if(a[0] != b[0] || a[1] != b[1])
    {
        return false;
    }
    return true;
}

bool chk2(string a, string b)
{
    if((a[2] == 'A' || a[2] == 'B' || a[2] == 'C') && (b[2] == 'A' || b[2] == 'B' || b[2] == 'C'))
    {
        return true;
    }
    if((a[2] == 'D' || a[2] == 'F') && (b[2] == 'D' || b[2] == 'F'))
    {
        return true;
    }
    return false;
}

bool chk3(string a, string b)
{
    char ca = a[2];
    char cb = b[2];
    if(cb < ca)
    {
        swap(ca, cb);
    }
    if(ca == 'A' && cb == 'B')
    {
        return true;
    }
    if(ca == 'B' && cb == 'C')
    {
        return true;
    }
    if(ca == 'D' && cb == 'F')
    {
        return true;
    }
    return false;
}

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a, c;
    string b, d;
    cin >> a >> b >> c >> d;
    if(a != c)
    {
        cout << "0000\n";
        return 0;
    }
    if(!chk(b, d))
    {
        cout << "1000\n";
        return 0;
    }
    if(!chk2(b, d))
    {
        cout << "1100\n";
        return 0;
    }
    if(!chk3(b, d))
    {
        cout << "1110\n";
        return 0;
    }
    cout << "1111\n";
    return 0;
}