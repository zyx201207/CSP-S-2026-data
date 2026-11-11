#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MX=500010,MN=300001;
ll n,m,a[MX],cnt[MX],r[MX],gm[MX],pos[MN],ans[MN];
void solve(ll x){
    for (ll i=x;i<=n;i++){
        if (r[i]!=n+1) i=r[i];
        cnt[i]++;
        cnt[gm[i]+1]--;
        i=gm[i];
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(gm,-1,sizeof(gm));
    cin>>n>>m;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    for (ll i=1;i<=n;i++){
        if (i!=pos[a[i]]) r[i]=pos[a[i]];
        else r[i]=n+1;
    }
    gm[n]=n;
    for (ll i=n-1;i>=1;i--)
    if (r[i]==n+1){
        if (gm[i+1]!=-1) gm[i]=gm[i+1];
        else gm[i]=i;
    }
    for (ll i=1;i<=n;i++) solve(i);
    for (ll i=1;i<=n;i++) cnt[i]+=cnt[i-1];
    for (ll i=1;i<=n;i++)
    if (r[i]==n+1) ans[a[i]]=cnt[i];
    for (ll i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}