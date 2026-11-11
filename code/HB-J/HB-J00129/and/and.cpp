#include <bits/stdc++.h>
using namespace std;
int a[2010],maxn=-999;int n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,greater<int> ());
    int ans=a[1];
    for(int i=2;i<=m;i++) ans&=a[i];
    cout<<ans;
    return 0;
}
