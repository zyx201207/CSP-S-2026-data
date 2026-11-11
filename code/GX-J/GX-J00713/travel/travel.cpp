#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w". stdout);
    int n,m;
    string x,y;
    cin >> n >> x >> m >> y;

    int t1 = 0,t2 = 0,t3 = 0,t4 = 0;
    if(n == m)
        t1 = 1;

    int r1 = 0, r2 = 0;
    int a = x[0] - '0';
    int b = y[0] - '0';
    r1 = r1 * 10 + a;
    r2 = r2 * 10 + b;
    r1 = r1 * 10 + int(x[1] - '0');
    r2 = r2 * 10 + int(y[1] - '0');

    if(r1 == r2 && t1)
        t2 = 1;

    if((x[2] >= 'A' && x[2] <= 'C') && (y[2] >= 'A' && y[2] <= 'C') && t2)
        t3 = 1;
    else if((x[2] == 'D' || x[2] == 'F') && (y[2] == 'D' || y[2] == 'F') && t2)
        t3 = 1;

    if(x[2] == 'A' && y[2] == 'B' && t3)
        t4 = 1;
    else if(x[2] == 'B' && y[2] == 'C' && t3)
        t4 = 1;
    else if(x[2] == 'D' && y[2] == 'F' && t3)
        t4 = 1;

    cout << t1 << t2 << t3 << t4;
    return 0;
}
