#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5,M=3e5+5;
ll n,m,a[N],sum[M],s[M],zui;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        memset(s,0,sizeof(s));
        zui=0;
        for(ll j=i;j<=n;j++){
            ll k;
            for(k=1;k<=zui;k++){
                if(s[k]==a[j]){
                    zui=k-1;
                    break;
                }
            }
            s[++zui]=a[j];
            if(j==n){
                for(ll l=1;l<=zui;l++){
                    sum[s[l]]++;
                }
            }
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
