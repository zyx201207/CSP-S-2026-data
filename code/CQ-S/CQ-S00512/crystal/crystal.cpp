#include<bits/stdc++.h>
using namespace std;
namespace SOLUTION{typedef long long ll;
    constexpr int maxn=5e5+3;
    ll a[maxn],sum[maxn];
    inline int Main(){int n;ll m;cin>>n>>m;
        for(int i=1;i<=n;++i)cin>>a[i];sort(a+1,a+n+1);
        int ans=0;for(int i=1;i<=n;++i){sum[i]=sum[i-1]+a[i];
            int l=0,r=i-1;while(l!=r){int mid=l+r>>1;
                if(ll(i-mid)*a[i]-sum[i]+sum[mid]<=m)r=mid;else l=mid+1;
            }ans=max(ans,i-l);
        }cout<<ans<<'\n';return 0;
    }
}
int main(){freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    SOLUTION::Main();return 0;
}