#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n,m,ans,a[maxn];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        // if (a[i]<0) a[i]=-a[i];
    }
    sort(a+1,a+1+n);
    int cur=0,cnt=0;
    int l=1;
    for (int i=1;i<=n;i++) {
        cur+=(i-l)*(a[i]-a[i-1]);
        cnt++;
        // cout<<i<<" "<<cur<<" "<<cnt<<'\n';
        while (cur>m) {
            cur-=a[i]-a[l];
            cnt--;
            l++;
        }
        // cout<<i<<" "<<cur<<" "<<cnt<<'\n';
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}