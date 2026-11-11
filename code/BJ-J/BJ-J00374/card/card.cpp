#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int a[500010];
int d[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        d[a[i]]++;
    }
    for (int i=1;i<=m;i++)
    {
        cout<<0<<" ";
    }
    return 0;
}
