#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace rp
{
    const int N=5e5+7;
    int a[N];
    void slow(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    void main() {
        slow();
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;i++) {cin>>a[i];}
        sort(a+1,a+n+1);
        int l=1,s=0,g=1,ans=1;
        for(int i=2;i<=n;i++) {
            s+=g*(a[i]-a[i-1]),g++;
            while(l<i&&s>m) {
                s-=a[i]-a[l],g--,l++;
            }
            ans=max(ans,g);
        }
        cout<<ans;
    }
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    rp::main();
}
