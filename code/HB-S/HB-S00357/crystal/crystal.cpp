#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans=-1,maxa=-1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    for(int j=1;j<=maxa;j++)
    {
        int s[N];
        for(int i=1;i<=n;i++)
        {
            s[i]=j-a[i];
        }
        sort(s+1,s+1+n);
        int cnt=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            if(sum==m) break;
            if(s[i]>=0&&sum+s[i]<=m)
            {
                cnt++;
                sum+=s[i];
            }
        }
        ans=max(ans,cnt);
        
    }
    cout<<ans;
    return 0;
}
