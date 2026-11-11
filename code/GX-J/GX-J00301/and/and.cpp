#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and5.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,m1[2000005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>m1[i];
    }
    sort(m1+1,m1+1+n);
    cout<<m1[n-m+1];
    return 0;
}
