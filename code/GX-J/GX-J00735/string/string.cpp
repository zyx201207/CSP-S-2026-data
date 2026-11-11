#include <bits/stdc++.h>
using namespace std;
struct sg
{
    long long r;
    char x;
}st[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long sx=0,xx=0;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> st[i].r >> st[i].x;
    }
    for(int i=1;i<=n;i++)
    {
        if(st[i].x!=st[i+1].x)
        {
            xx++;
            if(xx>=2)
            {
                sx+=st[i].r;
            }
        }
        else
        {
            cout << 0;
            return 0;
        }
    }
    cout << sx;
    return 0;
}
