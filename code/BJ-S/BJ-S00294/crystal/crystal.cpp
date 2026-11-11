#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
int n,k,sum,ans,cnt;
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    int l=1;
    for(int r=1;r<=n;r++) {
        sum+=(a[r]-a[r-1])*(r-l),ans++;
        while(l<=r&&sum>k) sum-=(a[r]-a[r-1]),l++,ans--;
        cnt=max(cnt,ans);
    }
    cout<<cnt;
    return 0;
}
