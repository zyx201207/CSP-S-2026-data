#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int n;
ll m;
ll a[N],sum[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,ans=0;
    for(int r=1;r<=n;r++){
        while(a[r]*(r-l+1)-(sum[r]-sum[l-1])>m&&l<=r) l++;
        if(l<=r) ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}