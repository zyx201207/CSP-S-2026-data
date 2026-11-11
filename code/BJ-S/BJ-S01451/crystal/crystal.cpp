#include<bits/stdc++.h>
using namespace std;
long long n,m,p;
int T;
long long a[500005];
long long b[500005];
map<long long,int> cnt;
int ans=1;
bool check(int x,int p)
{
    long long sum=b[p-1]-b[x-1];
    if((p-x)*a[p]-sum<=m)return 1;
    else return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i]+b[i-1];
    }
    for(int p=2;p<=n;p++)
    {
        if(a[p]==a[p-1])continue;
        int l=1,r=p-1;
        //cout<<p<<'\n';
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid,p))
                r=mid-1;
            else l=mid+1;
            //cout<<l<<' '<<r<<'\n';
        }
        ans=max(ans,p-r+cnt[a[p]]-1);
        //cout<<ans<<'\n'<<'\n';
    }
    cout<<ans;
    return 0;
}
