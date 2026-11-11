#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int used=0,cnt=0;
        for(int j=i;j>=1;j--)
        {
            if(used+a[i]-a[j]<=m)
            {
                used+=a[i]-a[j];
                cnt++;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}