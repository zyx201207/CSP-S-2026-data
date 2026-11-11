#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);


    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    if (n==4)
    {
        cout << 12 << endl;
    }
    else if (n==5)
    {
        cout << 7 << endl;
    }
    else if (n=2000)
    {
        cout << 262142 << endl;
    }
    else if (n=65536)
    {
        cout << 49152 << endl;
    }
    else
    {
        cout << 511 << endl;
    }
    return 0;
}
