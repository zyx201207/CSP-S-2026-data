#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,ans=0;
    ll m;
    cin>>n>>m;
    vector<ll>a(n+10);
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a.begin()+1,a.begin()+n+1);
    ll sum=0;
    for(int l=1,r=1;r<=n;++r)
    {
        sum+=(r-l)*(a[r]-a[r-1]);
        while(sum>m)
            sum-=a[r]-a[l++];
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}
