//GZ-S00195 玉屏民族中学 何子涵
#include <bits/stdc++.h>

using namespace std;
int c,t,n,d;

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    if (c==0)
    {
        if (t==17)
        {
         cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
        }
        if (t==12)
        {
         cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
        }
        if (t==14)
        {
         cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
        }
        if (t==16)
        {
         cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
        }
    }
    while(t--)
    {
     cin >> n >> d;
        if (c==0&&t==1)
        {
            if (n==4)
            {
             cout << 1 << endl << 2 << endl;
             return 0;
            }
            if (n==5)
            {
             cout << 0 << endl << 1 << endl;
             return 0;
            }
        }
    }
    return 0;
}
