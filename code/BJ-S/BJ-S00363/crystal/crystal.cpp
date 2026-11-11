#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=5e5+10;
ll n,ans=1;
ll m,a[maxn],sum[maxn];
ll getans(int pos){
    ll l=1,r=pos-1,tans=1;
    while (l<=r){
        ll mid=(l+r)/2;
        ll tmp=((pos-mid)*a[pos])-(sum[pos-1]-sum[mid-1]);
        //cout << l << " " << r << " " << mid << " " << tmp << " " << m << " " << tans << '\n';
        if (m==tmp) return max(tans,pos-mid+1);
        if (m>tmp){
            tans=max(tans,pos-mid+1);
            r=mid-1;
        }
        else l=mid+1;
    }
    return tans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<=n;i++){
        //cout << i << '\n';
        ans=max(ans,getans(i));
        //cout << '\n';
    }
    cout << ans << '\n';
    //for (int i=1;i<=n;i++)
    //    cout << getans(i) << '\n';
    return 0;
}
