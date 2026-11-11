#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,s[500005],t[300005],nxt[300005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    ll k=0;
    for(ll i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]!=s[i-1]){
            t[++k]=1;
        }else{
            t[k]++;
        }
    }
    ll sum=0;
    for(ll i=1;i<=k;i++){
        sum+=t[i];
        cout<<sum<<" ";
    }
    return 0;
}
