#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
array<ll,500003>a;
ll n,l=1,r=1,ans;
ull m,cnt;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin()+1,a.begin()+1+n);
    a[0]=a[1];
    a[n+1]=a[n];
    while(l<=r&&r<=n)
    {
        //cout<<"*";
        while(cnt<=m&&r<=n)
        {
            ++r;
            cnt+=(a[r]-a[r-1])*(r-l);
        }
        ans=max(ans,r-l);
        //cout<<cnt<<" "<<ans<<endl;
        while(cnt>=m&&l<=r)
        {
            cnt-=a[r]-a[l];
            ++l;
        }
    }
    cout<<ans;
    return 0;
}
