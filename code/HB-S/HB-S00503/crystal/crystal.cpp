#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n'
ll n,m;
void solve(){
    cin>>n>>m;
    vector<ll> a(n+1);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    if(m==0){
        unordered_map<ll,int> mp;
        for(int i = 0;i<n;i++){
            mp[a[i]]++;
        }
        int maxn = 0;
        for(auto i:mp){
            maxn = max(maxn,i.second);
        }
        cout<<maxn;
    }
    else{
        unsigned int minn = 0;
        while(m--){
            for(int i = 0;i<n;i++){
                if(a[i]<a[minn]){
                    minn = i;
                }
            }
            a[minn]++;
        }
        unordered_map<ll,int> mp;
        for(int i = 0;i<n;i++){
            mp[a[i]]++;
        }
        int maxn = 0;
        for(auto i:mp){
            maxn = max(maxn,i.second);
        }
        cout<<maxn;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int T = 1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
//40 tps you ma?
//O(nm)
//15:25 T1 end
