#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
using ll=long long;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll m;
    cin>>n>>m;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    vector<ll> sum(n+1);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        sum[i]=a[i];
        sum[i]+=sum[i-1];
        int l=1,r=i+1,mid;
        while(r-l>1)
        {
            mid=(l+r)>>1;
            auto check=[&](const int x)-> bool
            {
                return x*a[i]-sum[i]+sum[i-x]<=m;
            };
            if(check(mid))
            {
                l=mid;
            }
            else
            {
                r=mid;
            }
        }
        res=max(res,l);
    }
    cout<<res;
}
