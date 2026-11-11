#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll n,a[N],lst[N],nxt[N],d;
ll sr[N],sl[N],fl[N],fr[N];
ll tlst[N],tnxt[N];
void solve(){
    cin>>n>>d;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    lst[1]=1;
    for(ll i=2;i<=n;i++){
        lst[i]=lst[i-1];
        while(a[i]-a[lst[i]]>d){
            lst[i]++;
        }
        if(lst[i]!=i){
            tlst[lst[i]]++;
        }
    }
    nxt[n]=n;
    for(ll i=n-1;i>=1;i--){
        nxt[i]=nxt[i+1];
        while(a[nxt[i]]-a[i]>d){
            nxt[i]--;
        }
        if(nxt[i]!=i){
            tnxt[nxt[i]]++;
        }
        if(nxt[i]!=i&&lst[nxt[i]]==i){
            sr[i]=nxt[i];
            sl[nxt[i]]=i;
        }
    }
    for(ll i=1;i<=n;i++){
        fl[i]=1;
        if(sl[i]){
            fl[i]=fl[sl[i]]+1;
        }
    }
    for(ll i=n;i>=1;i--){
        fr[i]=1;
        if(sr[i]){
            fr[i]=fr[sr[i]]+1;
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(i==nxt[i]) continue;
        ll x=nxt[i];
        if(x==nxt[x]) continue;
        ll y=nxt[x];
        ll z=lst[y];
        if(lst[z]==i&&z+1==x){
            ans+=(fl[i]-1)*(fr[y]-1);
        }
        if(z+1==x){
            ans+=fr[y]-1;
        }
        ans+=tlst[x-1]-(lst[x]==x-1);
    }
    for(ll i=1;i<=n;i++){
        if(i==lst[i]) continue;
        ll x=lst[i];
        if(x==lst[x]) continue;
        ll y=lst[x];
        ll z=nxt[y];
        if(x+1==z){
            ans+=fl[y]-1;
        }
    }
    cout<<ans<<"\n";
    for(ll i=1;i<=n;i++) sl[i]=sr[i]=tlst[i]=tnxt[i]=0;
}
ll c,T;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--) solve();
    return 0;
}
