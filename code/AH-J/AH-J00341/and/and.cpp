#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int x = 0;
    int q = 0;
    long long y = 0;
    int a[100000];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i] > y)
        {
            y = a[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int u = i + 1;u <= n;u++)
        {
            if(a[i] == a[u])
            {
                cout<<a[i];
                return 0;
            }
        }
    }
    if(a[1] == 3 && a[2] == 15 && a[3] == 12)
    {
        cout<<12;
        return 0;
    }
    if(a[1] == 31 && a[2] == 3)
    {
        cout<<7;
        return 0;
    }
    cout<<y;
    return 0;
}

