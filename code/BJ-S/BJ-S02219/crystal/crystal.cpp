#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
ll m;
ll a[N];
ll cha[N];
ll sum[N];
bool check(ll id,ll x){
    if(sum[x]-sum[id+1]-(cha[id+1]*(id-x+1))<=m)return 1;
    else return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n-1;i>=1;i--){
        cha[i]=a[n]-a[i];
        sum[i]=sum[i+1]+cha[i];
    }
    ll ans=1;
    for(int i=n-1;i>=1;i--){
        ll l=1,r=i,cnt=1E18;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(i,mid)){
                cnt=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        ans=max(ans,(i+2)-cnt);
    }
    cout<<ans<<"\n";
    return 0;
}
