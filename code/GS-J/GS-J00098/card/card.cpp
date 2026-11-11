#include <bits/stdc++.h>
using namespace std;
long long n,m,a[10005];
int main()
{
    freopen("card.in","w",stdin);
    freopen("card.out","r",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int k;
    for(int i = 1;i <= n;i++)
    {
        cin >> k;
        if(a[i] != k)
            cout << k;
    }
    return 0;
}
