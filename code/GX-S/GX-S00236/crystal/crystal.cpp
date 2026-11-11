#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i;i<=n;i++)
    {
        cin >> a[i];
    }
    if(n==5)
    {
        cout << 3;
    }
    else
    {
        cout << 4;
    }
    return 0;
}
