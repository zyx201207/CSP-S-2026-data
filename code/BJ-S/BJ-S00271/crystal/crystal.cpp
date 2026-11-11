#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=5e5+5;
ll n,m;
ll a[N];
bool check(int x){
    ll sum=0,minn=1e18;
    for(int i=1;i<=x;i++)sum+=(a[x]-a[i]);
    minn=sum;
    //cout << x << " " << minn << "\n";
    for(int i=2;i<=n-x+1;i++){
        sum=sum-(a[i+x-2]-a[i-1])+(x-1)*(a[i+x-1]-a[i+x-2]);
        minn=min(minn,sum);
        //cout << x << " " << minn << "\n";
    }
    if(minn>m)return false;
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1); // ohno 3/4.in isn't low->high
    int l=0,r=n,ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        } else r=mid-1;
    }
    cout << ans << "\n";
    return 0;
}
