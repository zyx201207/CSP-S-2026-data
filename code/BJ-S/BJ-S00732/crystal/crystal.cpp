#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],ans=1,b[1000005];
priority_queue<pair<int,int> > q;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        b[i]=b[i-1]+a[i];
    }
    int l=1,r=1;
    while(r<=n)
    {
        if(m>=a[r]*(r-l+1)-(b[r]-b[l-1]))
        {
            ans=max(ans,r-l+1);
            r++;
        }
        else
        {
            l++;
        }
    }
    cout<<ans;
    return 0;
}
