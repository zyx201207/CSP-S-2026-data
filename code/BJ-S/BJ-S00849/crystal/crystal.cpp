#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500010],sum=0,l=1,tans=0,t=0,ans=0;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+(n+1));
    for(int i=1;i<=n;i++)
    {
        sum+=(i-1-t)*(a[i]-a[i-1]);
        tans++;
        while(sum>m&&l<=i) sum-=(a[i]-a[l]),tans--,l++,t++;
        ans=max(tans,ans);
    }
    cout << ans << endl;
    return 0;
}
