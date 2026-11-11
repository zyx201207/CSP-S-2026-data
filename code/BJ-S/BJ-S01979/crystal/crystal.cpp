#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    long long tmp=0;
    for(int i=1,j=1;i<=n;i++)
    {
        tmp+=(a[i]-a[i-1])*(i-j);
        while(tmp>m)
            tmp-=(a[i]-a[j++]);
        ans=max(ans,i-j+1ll);
    }
    cout<<ans;
    return 0;
}
