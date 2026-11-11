#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=-1E9;
vector<int> a(200005);
bool flaga=1,flagc;
bool f(int x)
{
    int y=x+1;
    return y&(y-1);
}
map<int,int> mp;
void dfs(int x,int y,int z,int beg)
{
    if(y>m)
    {
        ans=max(ans,z);
        return;
    }
    if(x>n) return;
    for(int i=beg+1;i<=n;i++)
    {
        dfs(x+1,y+1,z&a[i],i);
    }
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(f(a[i])) flaga=0;
        if(a[i]>4) flagc=0;
    }
    if(m==1)
    {
        int maxn=-1E9;
        for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
        cout<<maxn;
        return 0;
    }
    if(m==n)
    {
        int sum=a[1];
        for(int i=2;i<=n;i++) sum&=a[i];
        cout<<sum;
        return 0;
    }
    if(m==2)
    {
        int maxn=-1E9;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j) maxn=max(maxn,(a[i]&a[j]));
            }
        }
        cout<<maxn;
        return 0;
    }
    if(flaga)
    {
        sort(&a[1],&a[n+1]);
        cout<<a[n-m+1];
        return 0;
    }
    if(flagc)
    {
        int maxn=-1E9;
        for(int i=1;i<=n;i++) mp[a[i]]++;
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                if(mp[i]+mp[j]>=m) maxn=max(maxn,(i&j));
            }
        }
        cout<<maxn;
        return 0;
    }
    int mask=1;
    for(int i=1;i<=31;i++) mask*=2;
    mask-=1;
    dfs(1,1,mask,0);
    cout<<ans;
    return 0;
}
