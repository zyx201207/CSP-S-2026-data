#include<bits/stdc++.h>
#define int long long
#define mid ((l+r)>>1)
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans=1,sum;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int l=1,r=2;r<=n;r++){
        sum+=(r-l)*(a[r]-a[r-1]);
        while(sum>m)sum-=a[r]-a[l++];
        ans=max(ans,r-l+1);
    }
    cout<<ans;
}