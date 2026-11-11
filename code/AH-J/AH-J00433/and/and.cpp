#include <bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,a[12345],b[12345],l=0;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        int q;
        cin>>q;
        a[i]=q;
    }
    if (m==1){
        sort(a+1,a+1+n);
        cout<<a[n];
        return 0;
    }
    for(int i=1;i<=n/2;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            b[l]=a[i]&a[j];
            l++;
        }
    }
    sort(b+1,b+l+1);
    cout<<b[l];
    return 0;
}
