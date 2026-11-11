#include<bits/stdc++.h>
using namespace std;
long long n,m,c[500005],a[500005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    if(n<=5*1e5)sort(a+1,a+1+n);
    for(int i = 1;i <= n;i++)
    {
        long long tgt = a[i];
        long long v=i;
        for(int j = 1;j <= i;j++)
        {
            c[i]+=a[i]-a[j];
        }
        if(c[i]<=m and v>ans)
        {
            ans=v;
        }
    }
    cout << ans;
    return 0;
}
