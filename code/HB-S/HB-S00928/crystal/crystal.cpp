#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int m,a[N];
int n,ans,l,r;

signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    l=1;
    r=1;
    int cnt=0;
    while(cnt<=m and r<=n) {
        r++;
        if(r>n) break;
        int mon=(r-l)*(a[r]-a[r-1]);
        cnt+=mon;
        if(cnt>m) {
            r--;
            cnt-=mon;
            break;
        }
        ans=max(ans,r);
    }
    while(r<=n) {
        r++;
        if(r>n) break;
        cnt+=(r-l)*(a[r]-a[r-1]);
        while(cnt>m) {
            cnt-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}