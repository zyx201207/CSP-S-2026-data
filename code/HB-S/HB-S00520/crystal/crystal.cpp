#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int sum[N];

bool check(int x) {
    int all=a[x]*x;
    return all-sum[x]<=m;
}

void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        int l=max(1ll,i),r=n;
        while(l<r) {
            int mid=(l+r+1)>>1;
            if(a[mid]*(mid-i)-sum[mid]+sum[i]<=m) {
                l=mid;
            }
            else {
                r=mid-1;
            }
        }
        ans=max(ans,l-i);
    }
    cout<<ans;
    return ;
}

signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    cout<<'\n';
    return 0;
}