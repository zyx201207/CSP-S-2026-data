#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans=1;
long long m,a[500005],d[500005],sum;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
    {
        d[++cnt]=a[i+1]-a[i];
    }
    for(int i=1;i<=cnt;i++)
    {
        if(sum+ans*d[i]>m) break;
        sum+=ans*d[i];
        ans++;
    }
    cout<<ans;
    return 0;
}
