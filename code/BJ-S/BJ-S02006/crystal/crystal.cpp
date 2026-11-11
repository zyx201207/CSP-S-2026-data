#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
int n,m;
ll a[500500];
ll s[500500];
bool check(int x)
{
    ll sum=LLONG_MAX;
    for(int i=x;i<=n;i++)
    {
        ll cur=a[i]*(x-1)-(s[i-1]-s[i-x]);
        sum=min(sum,cur);
        //cout<<i-x+1<<' '<<i<<':';
        //cout<<a[i]*(x-1)<<' '<<(s[i-1]-s[i-x])<<endl;;
        //cout<<cur<<'\n';
        //cout<<"====\n";
    }
    //cout<<sum;
    return sum<=m;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        //cout<<s[i]<<' ';
    }
    //cout<<endl<<endl;
    sort(a+1,a+n+1);
    int l=1,r=n,ans=l;
    while(l<=r)
    {
        int mid=(l+r)/2;
        //cout<<mid<<'\n';
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
        //cout<<endl<<"======="<<endl;
    }
    cout<<ans;
}
