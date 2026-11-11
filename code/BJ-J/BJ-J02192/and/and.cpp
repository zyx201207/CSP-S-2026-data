#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long ans=a[n-1];
    for(int i=2;i<=m;i++)
    {
        ans&=a[n-i];
    }
    cout<<ans;
    //<<a[n-m];
    return 0;
}
