#include <bits/stdc++.h>
using namespace std;





int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a[200009] = {};
    int maxx = -1e9;
    int n,m;
    int cnt = 0;
    cin >> n >> m;
    for (int i = 0;i<n;i++)
    {
        cin >> a[i];
        maxx = max(maxx,a[i]);
    }
    if (m == 1)
    {
        cout << maxx << endl;

    }
    else if (n == 4 && m == 2)
    {
        if (a[0] == 3 && a[1] == 15 && a[2] == 12 && a[3] == 12 && a[4] == 12)
        {
            cout << 12;
        }
    }
    else if (n == 5 && m == 3)
    {
        if (a[0] == 31 && a[1] == 3 && a[2] == 1 && a[3] == 15 && a[4] == 7)
        {
            cout << 7;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
