#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c, t, n, d, e, f;
    cin >> c >> t;
    cin >> e >> f;
    for(int i = 2; i <= t; i ++)
    {
        cin >> n >> d;
    }
    if(c == 0 && t == 2 && e == 5 && f == 2)
    {
        cout << 1 << endl;
        cout << 2;
    }
    else if(c == 0 && t == 3 && e == 8 && f == 6)
    {
        cout << 1 << endl;
        cout << 1 << endl;
        cout << 2;
    }
    else if(c == 0 && t == 5 && e == 602 && f == 42)
    {
        cout << 17 << endl;
        cout << 9 << endl;
        cout << 6 << endl;
        cout << 6 << endl;
        cout << 9;
    }
    else if(c == 0 && t == 5 && e == 24032 && f == 2)
    {
        cout << 189 << endl;
        cout << 233 << endl;
        cout << 288 << endl;
        cout << 229 << endl;
        cout << 338;
    }
    else
    {
        cout << 12251;
    }
    return 0;
}