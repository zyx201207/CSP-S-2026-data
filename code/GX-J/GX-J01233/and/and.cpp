#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<a[n/2];
    return 0;
}
