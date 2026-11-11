#include<bits/stdc++.h>
using namespace std;
using ll =long long;
using pii=pair<int,int>;
using pll=pair<long long,long long>;

const double eps =1E-8;
const ll base1=131,base2=13331;
const ll mod1=1E9+7,mod2=1E9+9;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);

   ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<ll> f(n);
    f[0]=a[0];
    for(int i=1;i<n;i++) {
        f[i]=f[i-1]+a[i];
    }


    ll ans=1;
    for(int i=0;i<n;i++){
        ll l=0,r=i,mid=(l+r)/2;

        while (l<=r) {
            ll should=(i-mid)*a[i];
            ll now=f[i]-a[i]-f[mid]+a[mid];

            if(should-now<=m) {
                r=mid-1;
                ans=max(ans,i-mid+1);
            }
            else l=mid+1;
            mid=(l+r)/2;
        }
    }

    cout<<ans;
    return 0;
}
