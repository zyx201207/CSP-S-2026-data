#include <bits/stdc++.h>
using namespace std;
int c1, c2, l1, l2, r1, r2;
string s1, s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1!=c2)
    {
        cout << "0000" << endl;
        return 0;
    }
    else cout << 1;
    l1=s1[0]*10+s1[1]-528;
    l2=s2[0]*10+s2[1]-528;
    if(l1!=l2)
    {
        cout << "000" << endl;
        return 0;
    }
    else cout << 1;
    r1=s1[2]-64;
    r2=s2[2]-64;
    if(r1==6) r1--;
    if(r2==6) r2--;
    if(r1<=3&&r2<=3||r1>3&&r2>3) cout << 1;
    else
    {
        cout << "00" << endl;
        return 0;
    }
    if(r1-r2==1||r2-r1==1) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}
