#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=3*1e5+10;
#define FASTIO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
ll a[MAXN];
ll n,m;
map<ll,ll>ans;
void sol(ll start){
    deque<ll>d;
    map<ll,ll>exist;
    for(ll i=start;i<=n;++i){
        ll x=a[i];
        if(!exist[x]){
            exist[x]=1;
        }else{
            exist[d.front()]=0;
            d.pop_front();
            while(d.size()&&d.front()!=x){
                exist[d.front()]=0;
                d.pop_front();
            }
            exist[x]=1;
        }
        d.push_back(x);
    }
    while(d.size()){
        ++ans[d.front()];
        d.pop_front();
    }
}
int main(){
    FASTIO;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;++i){
        cin>>a[i];
    }
    for(ll i=1;i<=n;++i){
        sol(i);
    }
    for(ll i=1;i<=m;++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}
