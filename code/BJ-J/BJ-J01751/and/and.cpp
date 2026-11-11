#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a[200005];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int res=a[n-m+1];
    for(int i=n;i>n-m;i--)
    {
        res=res&a[i];
    }
    cout<<res;
}
