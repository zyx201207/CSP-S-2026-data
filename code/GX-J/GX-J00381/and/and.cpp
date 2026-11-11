#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;++i)
        cin >> a[i];
    int maxn=-1;
    sort(a+1,a+n+1);
    for(int i=n;i>1;--i)
    {
        int r=i-m+1;
        int ans=a[i];
        for(int j=i;j>=r;--j)
            ans&=a[j];
        maxn=max(maxn,ans);
    }
    cout << maxn;
    return 0;
}
