#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],d[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >>a[i];

    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++)
    {
        d[i]=d[i-1]+a[i];
    }
    long long ans=0,l=1,r=1,cnt=0;
    while(l<n)
    {
        if(a[l]*(l-r+1)-(d[l]-d[r-1]) <=m)
        {
            ans=max(ans,l-r+1);
            l++;
        }
        else
        {
            r++;
        }
    }
    cout << ans;
    return 0;
}
