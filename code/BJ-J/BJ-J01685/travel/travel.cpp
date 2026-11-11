#include <bits/stdc++.h>

using namespace std;

int sf[4] = {0,0,0,0};

int main()
{

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >>s2;
    if(c1 == c2)
    {
        sf[0] = 1;
    }
    string a1,a2;
    a1 = s1[0] + s1[1];
    a2 = s2[0] + s2[1];
    if(sf[0] == 1&&a1 == a2)
    {
        sf[1] = 1;
    }
    char b1,b2;
    b1 = s1[2];
    b2 = s2[2];
    if(sf[1] == 1&&b1 == 'D'&&b2 == 'F')
    {
        sf[2] = 1;
        sf[3] = 1;
    }
    else if(sf[1] == 1&&b1 == 'A'&&b2 == 'B')
    {
        sf[2] = 1;
        sf[3] = 1;
    }
    else if(sf[1] == 1&&b1 == 'B'&&b2 == 'C')
    {
        sf[2] = 1;
        sf[3] = 1;
    }
    else if(sf[1] == 1&&b1 == 'A'&&b2 == 'C')
    {
        sf[2] = 1;
    }
    else if(sf[1] == 1&&b1 == 'F'&&b2 == 'D')
    {
        sf[2] = 1;
        sf[3] = 1;
    }
    else if(sf[1] == 1&&b1 == 'B'&&b2 == 'A')
    {
        sf[2] = 1;
        sf[3] = 1;
    }
    else if(sf[1] == 1&&b1 == 'C'&&b2 == 'B')
    {
        sf[2] = 1;
        sf[3] = 1;
    }
    else if(sf[1] == 1&&b1 == 'C'&&b2 == 'A')
    {
        sf[2] = 1;
    }
    cout << sf[0] << sf[1] << sf[2] << sf[3];

    return 0;
}