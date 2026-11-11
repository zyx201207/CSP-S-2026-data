#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
ll last[200005];
ll n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll k=1;k<=n;k++){
        ll shu[n+5]={0};
        ll e=0;
        for(ll i=k;i<=n;i++){
            bool f=0;
            for(ll j=1;j<=e;j++){
                if(shu[j]==a[i]){
                    f=1;
                }
            }
            if(f){
                for(ll j=1;j<=e;j++){
                    if(shu[j]==a[i]){
                        e=j;
                    }
                }
            }else{
                shu[++e]=a[i];
            }
        }
        for(ll i=1;i<=e;i++){
            last[shu[i]]++;
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<last[i]<<" ";
    }
    return 0;
}
