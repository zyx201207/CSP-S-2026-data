#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void M_T_J_R(){
    /*
    I got only few points.

    So, I'm going to AFO.

    Since I AFO, I will recommend a light novel to you all.

    The name is Mushoku Tensei: Jobless Reincarnation.

    I love Eris Greyrat/ Roxy Migrudia Greyrat/ Sylphiette Greyrat/ Asia(?) Greyrat/ Norlon(?) Greyrat/ Synes(?) Greyrat.

    However, I can't even spell their names correctly.

    However, I'm still the most "Xiao" son of Jobless Reincarnation. 

    So, go to watch Mushoku Tensei: Jobless Reincarnation.

    I'm got angry to laugh by myself. 
    */
    }


ll n,k,root;
vector<ll> e[1000001];
namespace Fds{
    ll fa[1000001];
    ll dp[1000001];
    void dfs(ll u) {
        for(auto v:e[u])
            if(fa[u]!=v) {
                fa[v]=u;
                dfs(v);
                dp[u]=max(dp[u],dp[v]+1);
            }
    }
    pair<ll,ll> mn;
    void calc(ll u,ll upon) {
        ll mx=upon,smx=-1;
        for(auto v:e[u])
            if(fa[u]!=v) {
                if(dp[v]>mx) {
                    smx=mx;
                    mx=dp[v];
                } else {
                    if(dp[v]>smx) 
                        smx=dp[v];
                }
            }
        mn=min(mn,{mx+1,u});
        for(auto v:e[u])
            if(fa[u]!=v) {
                if(dp[v]==mx)
                    calc(v,smx+1);
                else
                    calc(v,mx+1);
            }
    }
    ll get(ll x) {
        for(ll i=1;i<=n;i++)
            fa[i]=dp[i]=0;
        dfs(x);
        mn={LONG_LONG_MAX,-1};
        calc(x,-1);
        return mn.second;
    }  
};
ll fa[1000001];
ll dp[1000001];    
void dfs(ll u) {
    for(auto v:e[u])
        if(fa[u]!=v) {
            fa[v]=u;
            dfs(v);
            dp[u]=max(dp[u],dp[v]+1);
        }
}
ll f[1000001];
vector<pair<ll,ll>> tmp;
void got(ll u,ll lim) {
    f[u]=dp[u]>=lim;
    for(auto v:e[u])
        if(fa[u]!=v) {
            got(v,lim);
            f[u]=f[u]+f[v];
        }
}
void gote(ll u,ll length,ll uponmx,ll mdd,ll llim) {
    ll mx=0,demx=0;
    for(auto v:e[u]) 
        if(fa[u]!=v) {
            if(dp[v]+1>mx) {
                demx=mx;
                mx=dp[v]+1;
            } else 
                if(dp[v]+1>demx)
                    demx=dp[v]+1;
        }
    for(auto v:e[u]) 
        if(fa[u]!=v) {
            if(dp[v]+1==mx)
                gote(v,length+1,demx+length,max(mdd+1,demx+1),llim);
            else
                gote(v,length+1,mx+length,max(mdd+1,mx+1),llim);
        }
    if(mdd<=llim)
        tmp.push_back({max(uponmx,length),f[u]});
}
struct tree{
    ll mn[20000001];
    void clear() {
        for(ll i=0;i<=n*4;i++)
            mn[i]=LONG_LONG_MAX;
    }
    void modify(ll i,ll l,ll r,ll x,ll y) {
        if(l==r) {
            mn[i]=y;
            return;
        }
        ll mid=(l+r)/2;
        if(x<=mid)
            modify(i*2,l,mid,x,y);
        else
            modify(i*2+1,mid+1,r,x,y);
        mn[i]=min(mn[i*2],mn[i*2+1]);
    }
    void modify(ll pos,ll val) {
        if(pos<=n)
            modify(1,1,n+1,pos+1,val);
    }
    ll query(ll i,ll l,ll r,ll x) {
        if(r<=x)
            return mn[i];
        ll mid=(l+r)/2;
        if(x<=mid)
            return query(i*2,l,mid,x);
        return min(query(i*2,l,mid,x),query(i*2+1,mid+1,r,x));
    }
    ll query(ll pos) {
        if(pos>=0)
            return query(1,1,n+1,pos+1);
        return LONG_LONG_MAX;
    }
}T1,T2,T0;
ll ans;
bool check(ll x) {
    /*
    -,mx
    -,demx
    -,none
    */
    T0.clear(),T1.clear(),T2.clear();
    got(root,x);
    if(f[root]<=k)
        return true;
    ll mx=0,demx=0,trimx=0;
    for(auto v:e[root]) {
        if(dp[v]+1>mx) {
            trimx=demx;
            demx=mx;
            mx=dp[v]+1;
        } else {
            if(dp[v]+1>demx) {
                trimx=demx;
                demx=dp[v]+1;
            } else 
                if(dp[v]+1>trimx) 
                    trimx=dp[v]+1;
        }
    }
    for(auto v:e[root]) {
        tmp.clear();
        gote(v,1,0,LONG_LONG_MIN,x);
        for(auto F:tmp) {
            ll len=F.first,val=F.second;
            if(x<len||k<val)
                continue;
            if(mx==dp[v]+1) 
                if(T0.query(x-len)<=k-val)    
                    return true;
            if(demx==dp[v]+1) 
                if(T1.query(x-len)<=k-val)
                    return true;
            if(mx!=dp[v]+1&&demx!=dp[v]+1)
                if(T2.query(x-len)<=k-val)
                    return true;
            if(mx==dp[v]+1) {
                if(trimx+len>x)
                    T1.modify(trimx,val);
                else
                    T1.modify(0,val);
                if(demx+len>x)
                    T2.modify(demx,val);
                else    
                    T2.modify(0,val);
            } 
            if(demx==dp[v]+1) {
                if(trimx+len>x)
                    T0.modify(trimx,val);
                else
                    T0.modify(0,val);
                if(mx+len>x)
                    T2.modify(mx,val);
                else
                    T2.modify(0,val);
            }
            if(dp[v]!=demx&&dp[v]!=dp[v]+1) {
                if(demx+len>x) 
                    T0.modify(demx,val);
                else
                    T0.modify(0,val);
                if(mx+len>x)
                    T1.modify(mx,val);
                else
                    T1.modify(0,val);
                if(mx+len>x)
                    T2.modify(mx,val);
                else
                    T2.modify(0,val);
            }

        }
    }
    return false;
}
void solve() {
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
        e[i].clear();
    for(ll i=1;i<=n;i++)
        fa[i]=dp[i]=0;
    for(ll i=1;i<n;i++) {
        ll u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    root=Fds::get(1);
    dfs(root);
    ll l=0,r=n;
    while(l<r) {
        ll mid=(l+r)/2;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<l<<'\n';
}
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    ll c,T;
    cin>>c>>T;
    while(T--)
        solve();
    return 0;
}
/*

... I just want to get n log^2 's scores

but I failed and get 0. 
*/
