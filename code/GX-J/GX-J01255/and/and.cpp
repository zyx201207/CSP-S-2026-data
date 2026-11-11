#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        ans=max((a[i]&a[i+1]),(a[i]&a[i+2]));

    }
    cout<<ans;
    return 0;
}
