#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using sg = string;

sg ac, ad, bc, bd;

bool pd(char cx, char cy)
{
    if((cx <= 'C') && (cy <= 'C')) return true;
    if((cx > 'C') && (cy > 'C')) return true;
    return false;
}

bool pdd(char cx, char cy)
{
    return((char(min(cx, cy))!='A') || (char(max(cx, cy))!='C'));
}

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> ac >> ad >> bc >> bd;
    if(ac == bc)
    {
        cout << "1";
        if(ad.substr(0, ad.size()-1) == bd.substr(0, bd.size()-1))
        {
            cout << "1";
            if(pd(ad[ad.size()-1], bd[bd.size()-1]))
                cout << "1" << (pdd(ad[ad.size()-1], bd[bd.size()-1])? "1":"0");
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
