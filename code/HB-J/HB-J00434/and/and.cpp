#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n,m;
multiset<ll> s;
ll dp[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        dp[i]=-1e9;
    }
    ll maxn=INT_MIN;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        s.insert(x);
        maxn=max(maxn,x);
    }
    dp[1]=maxn;
    s.erase(s.find(dp[1]));
    n--;
    for(int i=2;i<=m;i++){
        for(auto it:s){
            dp[i]=max(dp[i],dp[i-1]&it);
        }
        s.erase(s.find(dp[i]));
    }
    cout<<dp[m];
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    solve();
    return 0;
}
