#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,t=0,a[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        t++;
        if(t==m)
        {
            cout<<a[i];
        }
    }
    return 0;
}
