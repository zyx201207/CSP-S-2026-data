#include<bits/stdc++.h>
using namespace std;
using ll = int;
const ll N = 5e5 + 100;
ll a[N],cnt[N];
ll n,m;
void solvesort(){
    for(ll i=1;i<=n;i++)cnt[a[i]] ++;
    for(ll i=1;i<=m;i++)cout<<(cnt[i] + 1) / 2<<'\n';
}
void solve2(){
    for(ll i=1;i<=m;i++){
        ll ans = 0,cnt = 0;
        for(ll j=n;j>=1;j--){
            if(a[j] == i)cnt ++;
            ans += (cnt % 2);
        }
        cout<<ans<<' ';
    }
    cout<<'\n';
}
void solveBF(){
    set<ll> s;
    vector<ll> v;
    for(ll i=1;i<=n;i++){//枚举第i局
        s.clear(),v.clear();
        for(ll j=i;j<=n;j++){//枚举第j张
            if(s.count(a[j])){
                ll t = v.size();
                for(ll k=t-1;k>=0;k--){
                    if(v[k] == a[j]){
                        s.erase(v[k]);
                        v.pop_back();
                        break;
                    }
                    s.erase(v[k]);
                    v.pop_back();
                }
            }
            s.insert(a[j]);
            v.push_back(a[j]);
        }
        for(ll j=0;j<v.size();j++)cnt[v[j]] ++;
    }
    for(ll i=1;i<=m;i++)cout<<cnt[i]<<' ';
    cout<<'\n';
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    ll flag = 1;
    for(ll i=1;i<=n;i++)cin>>a[i],flag = (a[i-1] <= a[i]?flag:0);
    if(flag){
        solvesort();
        return 0;
    }
    if(m <= 2){
        solve2();
        return 0;
    }
    if(n * n * m <= 1e8)solveBF();
    return 0;
}