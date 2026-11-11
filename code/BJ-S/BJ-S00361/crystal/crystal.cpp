#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
vector<ll> v;
vector<ll> pre;
ll check(ll len){
    deque<ll> q;
    ll ans=1e18;
    for (int i=1;i<=n;i++){
        while (!q.empty() && i-q.front()+1>len){
            q.pop_front();
        }
        while (!q.empty() && v[q.back()]<v[i]){
            q.pop_back();
        }
        q.push_back(i);
        if (i>=len){
            ll sum=pre[i]-pre[i-len];
            ll need=v[q.back()]*len-sum;
            ans=min(ans,need);
        }
    }
    return ans;
}
ll bin(){
    int l=0,r=n;
    int ans=0;
    while (l<=r){
        int mid=(l+r)/2;
        if (check(mid)<=m){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    v.resize(n+1);
    pre.resize(n+1,0);
    for (int i=1;i<=n;i++){
        cin>>v[i];
        pre[i]=pre[i-1]+v[i];
    }
    sort(v.begin()+1,v.end());
    cout<<bin();
    return 0;
}