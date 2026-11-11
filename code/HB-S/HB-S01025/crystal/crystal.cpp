#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,ans=0,w[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (ll i=1;i<=n;i++) cin>>w[i];
    sort(w+1,w+n+1);
    ll sum=0,cnt=1,ans=0;
    if (m==0){
        for (ll i=2;i<=n;i++){
            cnt=1;
            for (ll j=1;j<i;j++){
                if (w[i]==w[j]) cnt++;
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
        return 0;
    }
    for (ll i=2;i<=n;i++){
        sum=0;
        for (ll j=1;j<i;j++) sum+=w[i]-w[j];
        if (sum<=m) cnt=i;
        else break;
    }
    cout<<cnt;
    return 0;
}
