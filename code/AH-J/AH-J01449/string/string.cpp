#include<bits/stdc++.h>
using namespace std;
struct st
{
    long long s;
    char l;
}a[200115];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string x,y;
    long long c = 0,d = 0;
    bool w = 1;
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i].s>>a[i].l;
        c += a[i].s;
        if(i != 1 && a[i].l != a[i-1].l)
            w = 0;
    }
    if(w)
    {
        cout<<0;
        return 0;
    }
    if(n == 1)
    {
        cout<<0;
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= a[i].s;j++)
        {
            if(x.size() < c/2)
            {
                x += a[i].l;
            }
            else
            {
                y += a[i].l;
            }
        }
    }
    for(int i = 0;i < min(x.size(),y.size());i++)
    {
        if(x[i] != y[y.size()-i-1])
        {
            d++;
        }
    }
    cout<<d;

    return 0;
}
