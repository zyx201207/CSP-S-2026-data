#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long ans=1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>n-m;i--)
    {
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
