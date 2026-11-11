#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    string a;
    string b;
    cin>>n>>a>>m>>b;
    int c = (a[2] - 'A' + 1);
    int d = (b[2] - 'A' + 1);
    if(n == m)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(a[0] == b[0] && a[1] == b[1] && n == m)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if((a[0] == b[0] && a[1] == b[1] && n == m) && ((c <= 3 && d <= 3) || (c > 3 && d > 3)))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if((a[0] == b[0] && a[1] == b[1] && n == m) && ((c - d == 1 || c - d == -1) && (!((c == 3 && d == 4) || (c == 4 && d == 3)))))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;

}
