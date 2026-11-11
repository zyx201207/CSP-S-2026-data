#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL N=500010;
LL a[N];
map<LL,LL>mp;
set<LL>st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    LL n,m;
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]=i;
        st.insert({a[i]});
    }
    for(auto u:st){cout<<mp[u]<<' ';}
    return 0;
}
