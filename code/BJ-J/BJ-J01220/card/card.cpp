#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    ll n,m;cin>>n>>m;
    ll a[500005],ans[500005]={0};
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        vector<ll> t;
        for(int k=i;k<=n;k++){
            bool check=1;
            for(ll j:t){
                if(j==a[k]) check=0;
            }
            if(check){
                t.push_back(a[k]);
            }else{
                while(t.size()>0){
                    t.pop_back();
                }
                t.push_back(a[k]);
            }
        }
        ans[t[0]]++;
    }
    for(int i=1;i<=m;i++){
        if(ans[i]!=0) cout<<ans[i]<<' ';
    }

    return 0;
}