#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
map<long long,long long> mp;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            mp[a[j]]++;
        }
    }
    for(auto i:mp){
        cout<<i.second<<" ";
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    solve();
    return 0;
}
