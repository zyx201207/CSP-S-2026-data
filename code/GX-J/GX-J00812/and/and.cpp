#include <bits/stdc++.h>
using namespace std;
int a[200005];
int n,m,max1=-1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        max1=max(max1,a[i]);
    }

    if(m==1)
       cout<<max1;
    if(m==2)
    {
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                max1=max(max1,a[i]&a[j]);
        cout<<max1;
    }
    return 0;
}
