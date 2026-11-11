#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
using namespace std;
int n;
ll m;
const int N=5e5+10;
ll a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=1,l=1;
    ll s=0;
    for(int i=2;i<=n;i++)
    {
        ll t=a[i]-a[i-1];
        s+=t*(i-l);
        while(s>m) s-=a[i]-a[l++];
        ans=max(ans,i-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}