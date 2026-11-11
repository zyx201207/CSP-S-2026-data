#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //freopen("travel.err","w",stderr);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    string c1,s1,c2,s2;
    bool f1 = 0,f2 = 0,f3 = 0,f4 = 0;
    cin >> c1 >> s1 >> c2 >> s2;

    //Part1
    if(c1 == c2)
    {
        cout << 1;
        f1 = 1;
    }
    else cout << 0;

    //Part2
    if(f1 == 1)
    {
        string tmp1 = "",tmp2 = "";
        for(int i = 0;i < s1.size()-1;i++)
        {
            tmp1 += s1[i];
        }
        for(int i = 0;i < s2.size()-1;i++)
        {
            tmp2 += s2[i];
        }
        //cerr << tmp1 << " " << tmp2;
        if(tmp1 == tmp2)
        {
            cout << 1;
            f2 = 1;
        }
        else cout << 0;
    }
    else cout << 0;

    //Part3
    char m1 = s1[s1.size()-1];
    char m2 = s2[s2.size()-1];
    if(f2 == 1)
    {
        if(m1 == 'F' && m2 != 'D')cout << 0;
        else if(m1 == 'D' && m2 != 'F')cout << 0;
        if(m2 == 'F' && m1 != 'D')cout << 0;
        else if(m2 == 'D' && m1 != 'F')cout << 0;
        else
        {
            cout << 1;
            f3 = 1;
        }
    }
    else cout << 0;
    
    //Part4
    if(f3 && (m1 + 1 == m2 || m1 - 1 == m2))
    {
        cout << 1;
    }
    else cout << 0;
    return 0;
}

void CSP_J(int AK)
{
    int RP = 100;
    int Inf = 0x3f3f3f3f;
    RP+=Inf;//!
}