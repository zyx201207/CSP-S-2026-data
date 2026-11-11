#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll e[1000005],n,m,r[1000005],f[1000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>e[i];
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++)f[j]=0;
        for(ll j=i;j<=n;j++){
            if(f[e[j]]==1){
                for(ll k=1;k<=m;k++){
                    f[k]=0;
                }
            }
            f[e[j]]=1;
        }
        for(ll j=1;j<=m;j++){
            if(f[j]==1){
                r[j]++;
            }
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<r[i]<<" ";
    }
    return 0;
}
