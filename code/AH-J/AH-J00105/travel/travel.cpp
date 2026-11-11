#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rc,rs,xc,xs;
    int a = 0,b = 0;
    bool c = false;
    cin >> rc >> rs >> xc >> xs;
    for (int i = 0;i < rc.size()-1;i++)
    {
        if (rc[i] == xc[i])
        {
            a++;
        }
    }
    if (a == 2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    for (int j = 0;j < rs.size()-2;j++)
    {
        if (rs[j] == xs[j])
        {
            b++;
        }
    }
    if (b == 2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if ((rs[2] == 'C' && xs[2] == 'D') || (rs[2] == 'D' && xs[2] == 'C'))
    {
        cout << 0;
    }
    if (b == 2 && (rs[2] != 'C' && xs[2] != 'D') || (rs[2] != 'D' && xs[2] != 'C'))
    {
        cout << 1;
    }
    if (rs[2] + 1 == xs[2] || xs[2] + 1 == rs[2])
    {
        if ((rs[2] != 'C' && xs[2] != 'D') || (rs[2] != 'D' && xs[2] != 'C'))
        {
            c = true;
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
