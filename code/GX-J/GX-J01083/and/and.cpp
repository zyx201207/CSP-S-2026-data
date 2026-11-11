#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[20005],b[20005],d=-1;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>n-m-1;i--)
    {
        d=d&a[i];
    }
    cout<<d;
    return 0;
}
