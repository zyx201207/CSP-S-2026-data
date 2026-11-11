#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=5e5+5;
ll vis[MAXN];
ll vis1[MAXN];
ll a[MAXN];
ll ch[MAXN];
map<ll, ll> mp;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    for(ll i=1;i<=n;i++){
        cin >> a[n-i+1];
    }
    for(ll i=1;i<=n;i++){
        vis1[i]=1;
        mp[a[i]]++;
        if(mp[a[i]]==2){
            mp[a[i]]--;
            vis1[i]=0;
            for(ll j=i-1;;j--){
                if(a[i]==a[j]&&vis1[j]==1) break;
                if(vis1[j]) mp[a[j]]--;
                vis1[j]=0;
            }

        }
        for(auto k:mp){
            if(k.second==1){
                // cout << k.first << " ";
                vis[k.first]++;
            }
        }
        // cout << endl;
    }
    // ll l=-1, r=-1; 
    // for(ll i=1;i<=n;i++){
    //     if(mp[a[i]]&&(mp[a[i]]<l||mp[a[i]]>r)){
    //         // cout << mp[a[i]] << endl;
    //         l=mp[a[i]], r=i;
    //         ch[mp[a[i]]]++;
    //     }
    //     else{
    //         // cout << i << " ";
    //         mp[a[i]]=i;
    //         ch[i]++;
    //         if(r==-1) continue;
    //         ch[r]--;
    //         ch[l-1]++;
    //     }
    // }
    // for(ll i=n;i>=1;i--){
    //     // cout << ch[i] << endl;
    //     ch[i]=ch[i+1]+ch[i];
    //     vis[a[i]]+=ch[i];
    // }
    for(ll i=1;i<=m;i++) cout << vis[i] << " ";
}