#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x,s=0,z=0;
    char a;
    string b;
    cin >>n;
    for(int i = 1;i<=n;i++)
    {
        cin >> x;
        cin >> a;
        s += x;
        for(int i = 1;i<=x;i++)
        {
            b += a;
        }
    }
    int c = s - 1,d=0;
    while(d < c)
    {
        if(b[d] != b[c])
        {
            z++;
        }
        c--;
        d++;
    }
    cout<<z;
    return 0;
}
