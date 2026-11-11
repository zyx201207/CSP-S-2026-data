#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans=1,sum=0;
int a[N],s[N];
bool book=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=a[i]-a[i-1];
        if(i==1) continue;
        if(s[i]!=s[i-1]) book=0;
    }
    if(book==1)
    {
        sum=0;
        for(int i=1;i<=n;i++)
        {
            if(sum+i*s[2]>m) break;
            sum+=i*s[2];
            ans++;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        sum=0;
        int cnt=0;
        int res=1;
        for(int j=i;j>=2;j--)
        {
            if(sum+cnt+s[j]>m) break;
            cnt+=s[j];
            sum+=cnt;
            res++;
        }
        ans=max(ans,res);
    }
    cout<<ans;
    return 0;
}
