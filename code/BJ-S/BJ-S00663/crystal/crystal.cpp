#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int a[500010];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) a[i]-=a[1];
    a[1]=0;
    int l,r,tot=0,ans=0;
    l=1,r=1;
    while(r<n){
        tot+=(r-l+1)*(a[r+1]-a[r]);
        r++;
        while(tot>m){
            tot-=(a[r]-a[l]);
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;

    return 0;
}
