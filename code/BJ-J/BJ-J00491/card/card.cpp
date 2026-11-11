#include<bits/stdc++.h>
using namespace std;
using Ull = unsigned long long;
constexpr Ull N = 2e5+10,M = 3e5+10;
int n,m,a[N],nxt[M],t[M];
void solve(int k){
    //cout<<k<<": ";
    for(int i=k;i<=n;++i){
        if(nxt[a[i]]>i){
            i = nxt[a[i]];
        }
        //cout<<a[i]<<" ";
        ++t[a[i]];
    }
    //cout<<endl;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    unordered_map<int,size_t> mp;
    mp.reserve(m);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(mp.find(a[i])!=mp.end()){
            nxt[a[i]] = i;
        }else nxt[a[i]] =-1;
        mp[a[i]]=i;
    }

    for(int i=1;i<=n;++i){
        solve(i);
    }

    for(int i=1;i<=m;++i)
        cout<<t[i]<<" ";
    cout<<flush;
    return 0;
}
