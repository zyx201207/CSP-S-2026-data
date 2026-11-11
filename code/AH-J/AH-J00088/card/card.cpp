#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],s[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=1;i<=n;i++){
        ll t[m+5];
        memset(t,0,sizeof(t));
        for(ll j=i;j<=n;j++){
            if(t[a[j]]==0) t[a[j]]=j;
            else{
                ll l=t[a[j]];
                for(ll x=l;x<=j;x++){
                    t[a[x]]=0;
                }
                t[a[j]]=j;
            }
        }
        for(ll j=1;j<=m;j++){
            if(t[j]!=0) s[j]++;
        }
    }
    for(ll i=1;i<=m;i++) cout<<s[i]<<' ';
    return 0;
}
