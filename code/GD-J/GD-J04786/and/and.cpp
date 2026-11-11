#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ans=0;
    cin>>n>>m;
    int a[200001];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n);
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,a[i]&a[i+1]);
    }
    cout<<ans;
    return 0;
}
