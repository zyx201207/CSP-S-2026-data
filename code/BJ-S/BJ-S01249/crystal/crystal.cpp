#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];int s[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        s[i]=a[i]-a[i-1];
    }
    int l=1,r=2,ans=0,cnt=-1,maxx=1;
    for(int r=2;r<=n;r++)
    {
        ans+=(r-l)*s[r];
        if(ans>m)
        {
            cnt=max(cnt,maxx);
            while(ans>m)
            {
                ans-=a[r]-a[l];
                l++;
                maxx--;
            }

        }
        maxx++;
    }
    if(cnt==-1)
        cnt=maxx;
    cout<<cnt;
    return 0;
}
