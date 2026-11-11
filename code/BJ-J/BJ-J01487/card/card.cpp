#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,M=3e5+5;
ll a[N],ans[M],last[M];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        last[a[i]]=i;
    }
    for(ll i=1;i<=m;i++)ans[i]=0;
    for(ll i=1;i<=n;i++){
        ll now=i;
        while(now<=n){
            if(last[a[now]]>now){
                now=last[a[now]];
            }else{
                ans[a[now]]++;
                now++;
            }
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
    return 0;
}