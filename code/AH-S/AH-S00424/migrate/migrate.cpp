#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct nd{
    ll a,b;
};
ll t,n,d,s[2000010],mn,q,ans;
void dfs1(ll aa,ll a2,ll cnt){
    if(aa==a2){
        mn=min(mn,cnt);
        return;
    }
    for(ll i=aa+1;;i++){
        if(abs(s[i]-s[aa])<=d){
            dfs1(i,a2,cnt+1);
        }
    }
    return;
}
void dfs2(ll aa,ll a1,ll a2,ll cnt){
    if(aa==a2){
        if(cnt==mn){
            q++;
        }
        return;
    }
    for(ll i=aa+1;i<=n;i++){
        if(abs(s[i]-s[aa])<=d){
            dfs2(i,a1,a2,cnt+1);
        }
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>t>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(ll i=1;i<=n;i++){
            cin>>s[i];
        }
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                mn=LLONG_MAX;
                q=0;
                dfs1(i,j,0);
                dfs2(i,i,j,0);
                if(q==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
