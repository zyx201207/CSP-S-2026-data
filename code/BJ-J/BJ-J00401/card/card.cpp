#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[500005],b[300005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    cout <<n-1<<" ";
    for(int i=2;i<=m-1;i++)
    {
        cout <<a[i]-1<<" ";
    }
    cout <<n;
    return 0;
}
