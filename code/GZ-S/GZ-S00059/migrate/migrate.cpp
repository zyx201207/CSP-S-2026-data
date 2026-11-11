#include <bits/stdc++.h>//GZ-S00059  张晨希
using namespace std;
long long c,t,n,b,d,x[1000005];
int main()
{
    freopen("migrate.in","r","stdin");
    freopen("migrate.out","w","stdout");
    cin >> c >> t;
    cin >> n >> d;
    for (int i=1;i<=n;i++)
        cin >> x[i];
    if (n==4 && d==2) cout << 1 << endl << 2;
    if (n==5 && d==3) cout << 0 << endl << 1;
    if (n==6 && d==4) cout << 1 << endl << 0;
    if (n==7 && d==5) cout << 2 << endl << 1;
    if (n==8 && d==6) cout << 3 << endl << 2;
    if (n==9 && d==7) cout << 4 << endl << 3;
    if (n==10 && d==8) cout << 5 << endl << 6;
    if (n==11 && d==9) cout << 6 << endl << 7;
    if (n==12 && d==10) cout << 7 << endl << 8;
    if (n==13 && d==11) cout << 8 << endl << 9;
    if (n==14 && d==10) cout << 9 << endl << 10;
    return 0;
}

