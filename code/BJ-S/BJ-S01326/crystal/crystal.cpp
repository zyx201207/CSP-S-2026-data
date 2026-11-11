//pts in optimistic:100
#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rof(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define sc second
#define pb push_back
#define pii pair<int,int>
#define vec vector
using namespace std;
const int N=5e5+5;
int n,a[N],m;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;For(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);
    int now=0;
    int sum=0,ans;
    Rof(i,n,1)
    {
        if(sum+a[n]-a[i]>m)
            break;
        sum+=a[n]-a[i];
        now=i;
    }
    ans=n-now+1;
    // cout<<now<<' '<<sum<<'\n';
    Rof(i,n-1,1)
    {
        sum-=(i+1-now+1)*(a[i+1]-a[i]);
        while(now>=2&&sum+a[i]-a[now-1]<=m)
            now--,sum+=a[i]-a[now-1];
        ans=max(ans,i-now+1);
    }
    cout<<ans<<'\n';
    return 0;
}