#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],b[500005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i]-a[i-1];
    }
    int ans=1;
    for(int i=n;i>1;i--)
    {
        int cost=0,co=0,cnt=1;
        for(int j=i;j>1;j--)
        {
            co+=b[i];
            if(cost+co<=m)
            {
                cost+=co;
                ++cnt;
            }
            else
            {
                break;
            }
        }
        ans=max(cnt,ans);
    }
    cout<<ans<<'\n';
    return 0;
}
