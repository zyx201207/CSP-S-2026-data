#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel5.in","r",stdin);
    freopen("travel5.out","w",stdout);
    string n,m;
    string a,b;
    cin >> n >> a >> m >> b;
    int o,p,q,r;
    o = int(n[0] - 48) * 10 + int(n[1] - 48);
    q = int(m[0] - 48) * 10 + int(m[1] - 48);
    p = int(a[0] - 48) * 10 + int(a[1] - 48);
    r = int(b[0] - 48) * 10 + int(b[1] - 48);
    int e = 0,f = 0,g = 0,h = 0;
    if(o == q)
    {
        e = 1;
        if(p == r)
        {
            f = 1;
            if((a[2] == 'A' && b[2] == 'B') || (a[2] == 'B' || b[2] == 'C') || (a[2] == 'A' && b[2] == 'C') || (a[2] == 'D' && b[2] == 'F'))
            {
                g = 1;
                if((a[2] == 'A' && b[2] == 'B') || (a[2] == 'B' || b[2] == 'C') || (a[2] == 'D' && b[2] == 'F')) h = 1;
                else h = 0;
            }
            else g = 0;
        }
        else f = 0;
    }
    else e = 0;
    cout << e << f << g << h;
    return 0;
}
