#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000010],n,d,cnt,minn=0x3f3f3f3f;
void dfs(ll xb,ll v,ll ccnt){
    if(xb==v){
        minn=min(minn,ccnt);
        return;
    }
    for(ll i=xb+1;i<=n;i++){
        if(a[i]-a[xb]<=d) dfs(i,v,ccnt+1);
        else break;
    }
    return;
}
void dfs1(ll xb,ll v,ll ccnt){
    if(xb==v){
        if(ccnt==minn) cnt++;
        return;
    }
    for(ll i=xb+1;i<=n;i++){
        if(a[i]-a[xb]<=d) dfs(i,v,ccnt+1);
        else break;
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(ll i=1;i<=n;i++) cin>>a[i];
        ll ans=0;
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                dfs(i,j,2);
                dfs1(i,j,2);
                if(cnt==2) ans++;
                cnt=0;
                minn=0x3f3f3f3f;
            }
        }
        cout<<ans<<endl;
        memset(a,0,sizeof(a));
    }
    return 0;
}
