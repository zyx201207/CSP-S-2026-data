#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    int g;
    char h;
    int m;
    char n;
    for(int i=0;i<b.size();i++)
    {
        g = b[0]*10+b[1];
        h = b[2];
    }
    for(int i=0;i<d.size();i++)
    {
        m = d[0]*10+d[1];
        n = d[2];
    }
    if(a == c)
    {
        cout << "1";
    }
    else
    {
        cout << "0000";
        return 0;
    }
    if(m == g)
    {
        cout << "1";
    }
    else
    {
        cout << "000";
        return 0;
    }
    if((h == 'A'&& n == 'B') || (h == 'B'&& n == 'A') ||(h == 'B'&& n == 'C') || (h == 'C'&& n == 'B'))
    {
        cout << "11";
        return 0;
    }
    else if((h == 'A'&& n == 'C') || (h == 'C'&& n == 'A'))
    {
        cout << "10";
        return 0;
    }
    else if((h == 'F' && n == 'D') || (h == 'D' && n == 'F'))
    {
        cout << "11";
        return 0;
    }
    else
    {
        cout << "00";
        return 0;
    }
    return 0;
}

