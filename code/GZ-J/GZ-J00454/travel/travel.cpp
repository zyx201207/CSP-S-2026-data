//GZ-J00454 华东师范大学附属贵阳学校 蒋泽赟
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int na = (a[0] - '0') * 10 + a[1] - '0';
    int nb = (b[0] - '0') * 10 + b[1] - '0';
    char nc = b[2];
    int ma = (c[0] - '0') * 10 + c[1] - '0';
    int mb = (d[0] - '0') * 10 + d[1] - '0';
    char mc = d[2];
    cout << (na == ma) << (na == ma && nb == mb);
    if (na == ma && nb == mb && ((nc <= 'C' && mc <= 'C') || (nc > 'C' && mc > 'C')))
    {
        cout << 1;
        if (abs(nc - mc) == 1) cout << 1;
        else cout << 0;
    }
    else
    {
        cout << "00";
    }
    return 0;
}
