#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define ffor(i,a,b) for(ll i=(a);i<=(b);++i)
#define roff(i,a,b) for(ll i=(a);i>=(b);--i)
const ll N=500010;
ll n,m,a[N],b[N],cnt[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    ffor(i,1,n) cin>>a[i];
    map<ll,ll> mp;
    ffor(i,1,n){
        ll r=0;//[1,r]
        mp.clear();
        ffor(j,i,n){
            if(mp[a[j]]==1){
                while(r>1&&b[r]!=a[j]) mp[b[r]]=0,r--;
            }else b[++r]=a[j];
            mp[a[j]]=1;
        }
        ffor(i,1,r) cnt[b[i]]++;
    }
    ffor(i,1,m) cout<<cnt[i]<<" ";
    return 0;
}
