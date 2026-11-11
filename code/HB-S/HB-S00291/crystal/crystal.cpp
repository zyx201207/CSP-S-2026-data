#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
ll n,m,a[MAXN],sum[MAXN]; int ans=1;

ll check(int l,int r){
    ll cnt=(r-l+1)*a[r]-sum[r]+sum[l-1];
    return cnt<=m;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int k=1;k<=n;k++){
        int l=1,r=k-1,ansl=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid,k)){
                r=mid-1;
                ansl=max(ansl,mid);
            }else{
                l=mid+1;
            }
        }
        if(check(l,k))ansl=l;
        if(ansl!=-1)ans=max(ans,k-ansl+1);
    }
    cout << ans << "\n";
    return 0;
}