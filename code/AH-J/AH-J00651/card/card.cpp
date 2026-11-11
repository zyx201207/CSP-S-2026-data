#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500010],cnt[300010],ans[500010],id[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++){
        ll tot=0;
        memset(id,0,sizeof id);
        for(ll j=i;j<=n;j++){
            ll k=a[j];
            if(id[k]==0){
                ans[++tot]=k;
                id[k]=tot;
            }else{
                for(ll jj=id[k]+1;jj<=tot;jj++)id[ans[jj]]=0;
                tot=id[k];
            }
        }
        for(ll j=1;j<=tot;j++)cnt[ans[j]]++;
    }
    for(ll i=1;i<=m;i++){
        printf("%lld ",cnt[i]);
    }
    return 0;
}
