#include<bits/stdc++.h>
using namespane std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[10086];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int r=2047,maxx=0;
    for(int i=1;i<=n;i++)
    {
        r=2047;
        for(int j=i;j<=i+m;j++)
        {
            r&=a[i];
        }
        if(r>=maxx)
        {
            maxx=r;
        }
    }
    cout<<maxx;
    return 0;
}
