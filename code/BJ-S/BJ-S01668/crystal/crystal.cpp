#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int sum=1,now=0,ans=0;
    for(int i=2;i<=n;i++){
        now+=((i-1)-sum+1)*(a[i]-a[i-1]);
        while(now>m)now-=a[i]-a[sum++];
        ans=max(ans,i-sum+1);
    }cout<<ans;
    return 0;
}
//Oct31==Dec25?
