#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll n,m,s,a[N],l[3010],f[3010],o[3010];
void try16(){
    ll sum=1,ans,p=0;
    for(ll i=2;i<=n;i++){
        if(a[i]==a[i-1])sum++;
        else{
            ans=0;
            for(ll j=1;j<=sum;j+=2)ans+=j+p;
            p=i-1;
            cout<<ans<<" ";
            sum=1;
        }
    }
    ans=0;
    for(ll j=1;j<=sum;j+=2)ans+=j+p;
    cout<<ans;
    return ;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    ll sf=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        sf+=(a[i]<a[i-1]);
    }
    if(sf==0){
        try16();
        return 0;
    }
    for(ll i=1;i<=n;i++){
        memset(l,0,sizeof l);
        memset(o,0,sizeof o);
        for(ll j=i;j<=n;j++){
            if(l[a[j]]){
                for(ll k=1;k<=m;k++)if(l[k]>l[a[j]])l[k]=0;
                s=l[a[j]];
            }
            else{
                o[++s]=a[j];
                l[a[j]]=s;
            }
        }
        for(ll j=1;j<=s;j++)f[o[j]]++;
    }
    for(ll i=1;i<=m;i++)cout<<f[i]<<" ";
    return 0;
}
