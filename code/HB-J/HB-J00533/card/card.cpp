#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],t[300005],ans[300005];
vector<ll> f;
bool pd(ll q,ll w[]){
    ll tmp=w[1];
    for(ll i=2;i<=q;i++){
        if(w[i]<tmp) return 0;
        tmp=w[i];
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    if(pd(n,a)){
        for(ll i=1;i<=n;i++){
            ans[a[i]]=i;
        }
        for(ll i=1;i<=m;i++){
            cout<<ans[i]<<' ';
        }
        return 0;
    }
    f.push_back(0);
    for(ll i=1;i<=n;i++){
        ll cnt=0;
        for(ll j=i;j<=n;j++){
            if(t[a[j]]!=0){
                for(ll k=t[a[j]]+1;k<=cnt;k++){
                    t[f[t[a[j]]+1]]=0;
                    f.erase(f.begin()+t[a[j]]+1);
                }
                cnt=t[a[j]];
            }else{
                f.push_back(a[j]);
                cnt++;
                t[a[j]]=cnt;
            }
        }
        for(ll j=cnt;j>=1;j--){
            ans[f[j]]++;
            t[f[j]]=0;
            f.pop_back();
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
