#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a,b,c,d) for(ll (a)=(b);(a)<=(c);(a)+=(d))
#define per(a,b,c,d) for(ll (a)=(b);(a)>=(c);(a)-=(d))
#define endl '\n'
#define pii pair<ll,ll>
#define _1 first
#define _2 second

ll c,t;
ll n,d;
ll a[2000010];
ll f[2000010], g[2000010];
constexpr ll inf=3e18+10;

pii calcbefore(ll i) {
    ll x=-1,y=-1; 
    // rep(j,1,i-1,1) if(a[j]+d>=a[i]) {
    //     x=j;
    //     break;
    // }
    x=upper_bound(a+1, a+i, a[i]-d-1)-a;
    if(!(a[x]>=a[i]-d)) x=-1;
    if(x<1||x>i-1) x=-1;
    // per(j,i-1,1,1) {
    //     if(a[j]+d<a[i+1]) {
    //         y=j;
    //         break;
    //     }
    // }
    y=upper_bound(a+1, a+i, a[i+1]-d-1)-a-1;
    if(!(a[y]<a[i+1]-d)) y=-1;
    if(y<1||y>i-1) y=-1;
    // cout<<i<<" "<<x<<" "<<y<<endl;
    return {x,y};
}
pii calcafter(ll i) {
    ll x=-1, y=-1;
    // per(j,n,i+1,1) {
    //     if(a[j]-d<=a[i]) {
    //         y=j;
    //         break;
    //     }
    // }
    y=upper_bound(a+i+1, a+n+1, a[i]+d)-a-1;
    if(!(a[y]<=a[i]+d)) y=-1;
    if(y<i+1||y>n) y=-1;
    // rep(j,i+1,n,1) {
    //     if(a[j]-d>a[i-1]) {
    //         x=j;
    //         break;
    //     }
    // }
    x=upper_bound(a+i+1, a+n+1, a[i-1]+d)-a;
    if(!(a[x]-d>a[i-1])) x=-1;
    if(x<i+1||x>n) x=-1;
    return {x,y};
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--) {
        cin>>n>>d;
        rep(i,1,n,1) cin>>a[i];
        a[0]=-inf;
        a[n+1]=inf;
        rep(i,1,n,1) {
            f[i]=1;
            pii t=calcbefore(i);
            ll x=t._1, y=t._2;
            if(x==-1||y==-1||x>y) continue;
            f[i]+=y-x+f[x];
        }
        per(i,n,1,1) {
            g[i]=1;
            pii t=calcafter(i);
            ll x=t._1, y=t._2;
            if(x==-1||y==-1||x>y) continue;
            g[i]+=y-x+g[y];
        }
        // rep(i,1,n,1) cout<<f[i]<<" ";
        // cout<<endl;
        // rep(i,1,n,1) cout<<g[i]<<" ";
        // cout<<endl;
        ll ans=0;
        rep(i,2,n-2,1) {
            // 判定存在这样的u与这样的v对于这一组(i,i+1)
            // 如果有，u向左扩展v向右扩展，贡献即为cntu*cntv
            ll x=i, y=i+1;
            // ll u=lower_bound(a+1, a+x, a[y]-d)-a, v=upper_bound(a+y+1, a+n+1, a[x-1]+d)-a;
            // if(u==0||v==n+1) continue;
            // // cout<<x<<" "<<y<<endl;
            // // cout<<"TESTu: "<<u<<endl;
            // if(a[y+1]-a[u]<=d) continue;
            // // cout<<"TESTv: "<<v<<endl;
            // if(a[v]-a[x]>d) continue;
            // cout<<u<<" "<<x<<" "<<y<<" "<<v<<endl;
            pii t1=calcbefore(y), t2=calcafter(x);
            if(t1._1==-1||t1._2==-1) continue;
            if(t2._1==-1||t2._2==-1) continue;
            // ll cntu=f[t1._1], cntv=g[t2._2];
            t1._2=min(t1._2,x-1);
            t2._1=max(t2._1,y+1);
            if(t1._1>t1._2) continue;
            if(t2._1>t2._2) continue;
            // cout<<t1._1<<" "<<t1._2<<" "<<x<<" "<<y<<" "<<t2._1<<" "<<t2._2<<endl;
            ans+=(f[t1._1]+t1._2-t1._1)*(g[t2._2]+t2._2-t2._1);
        }
        cout<<ans<<endl;
    }
    return 0;
}