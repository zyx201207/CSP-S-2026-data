#include<bits/stdc++.h>
using namespace std;
namespace mycode{
    typedef long long ll;
    int n;ll m;
    ll a[500005];
    int ans;
    void solve(){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        int l=1;ll s=0;
        ans=1;
        for(int i=2;i<=n;i++){
            s+=(i-l)*(a[i]-a[i-1]);
            while(s>m){s-=(a[i]-a[l]);l++;}
            ans=max(ans,i-l+1);
        }
        printf("%d\n",ans);
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    mycode::solve();
    return 0;
}