#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("andin","r",stdin);
    freopen("andout","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);

    for(int i=n-2;i>n-m-1;i--)
    {
        a[i]&=a[i-1];
    }
    cout<<a[n-m];
    return 0;
}
