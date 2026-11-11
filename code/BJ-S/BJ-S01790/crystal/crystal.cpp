#define ll long long

#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5*5+7;

ll n,m,a[MAXN],c[MAXN],maxm;

ll ans=1;

void dfs(ll l,ll r,ll now){
    if(now<=m){
        ans=max(ans,r-l+1);
    }
    if(l+1<r){
        ll nxt=now-(a[r]-a[l]);
        dfs(l+1,r,nxt);
    }
    if(r-1>l){
        ll nxt=now-(c[r]*(r-1));
        dfs(l,r-1,nxt);
    }
}

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;

    for(int i=1;i<=n;++i){
        cin>>a[i];
    }


    sort(a+1,a+n+1);

    for(int i=1;i<=n;++i){
        c[i]=a[i]-a[i-1];
        maxm+=c[i]*(i-1);
    }

    if(maxm<=m){
        cout<<n;
        return 0;
    }

    //Special A
    bool ta=true;
    for(int i=1;i<=n;++i){
        if(a[i]!=i){
            ta=false;
        }
    }
    if(ta==true){
        ll tai=1;
        for(tai=1;m>=0;++tai){
            m-=tai;
        }
        ans=tai-1;
        cout<<ans;
        return 0;
    }

    //Special B
    ll td=a[2]-a[1];
    for(int i=2;i<=n;++i){
        if(a[i]-a[i-1]!=td){
            td=-1;
        }
    }
    if(td!=-1){
        ll tdi=1;
        for(tdi=1;m>=0;++tdi){
            m-=tdi*td;
        }
        ans=tdi-1;
        cout<<ans;
        return 0;
    }


    dfs(1,n,maxm);

    cout<<ans;

    return 0;
}
