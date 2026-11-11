#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        m=max(a,m);
    }
    cout<<m;
    return 0;
}

