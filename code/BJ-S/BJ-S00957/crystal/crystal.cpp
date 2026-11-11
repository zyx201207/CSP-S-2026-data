/*#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500001];
bool check(int x)
{
    int cnt=0;
    for(int i=1;i<=x;i++)
        cnt+=(a[x]-a[i]);
    return cnt<=m;
}
signed main()
{
    freopen("crystal4.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<=r)
    {
        //cout<<l<<' '<<r<<'\n';
        int mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<r;
    return 0;
}*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500001],ans[500001];
int check(int x)
{
    int cnt=0,cur=0;
    for(int i=x;i>=1;i--)
    {
        if(cnt+a[x]-a[i]>m)return cur;
        cnt+=(a[x]-a[i]);
        cur++;
    }
    return cur;
}
int check1(int x)
{
    int cnt=0,cur=0;
    for(int i=n;i>=1;i--)
    {
        if(a[i]>x)continue;
        if(cnt+x-a[i]>m)return cur;
        cnt+=(x-a[i]);
        cur++;
    }
    return cur;
}
bool ls()
{
    for(int i=2;i<=n;i++)
        if(a[i]!=a[1])return 0;
    return 1;
}
bool jz()
{
    for(int i=2;i<=n;i++)
        if(a[i]-a[i-1]!=a[2]-a[1])return 0;
    return 1;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=5000)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,check(i));
        }
        cout<<ans;
        exit(0);
    }
    else if(a[n]<=100)
    {
        int ans=0;
        for(int i=1;i<=100;i++)
        {
            ans=max(ans,check1(i));
        }
        cout<<ans;
        exit(0);
    }
    else if(ls())
    {
        cout<<1;
        exit(0);
    }
    else if(jz())
    {
        int x=a[2]-a[1];
        int cnt=0;
        int ans=0;
        for(int i=x;i<=a[n]-a[1];i+=x)
        {
            cnt+=i;
            if(cnt>=m)
            {
                cout<<ans;
                exit(0);
            }
            ans++;
        }
    }
    return 0;
}
