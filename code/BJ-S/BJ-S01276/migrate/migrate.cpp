#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[2000050],pl[2000050];
pair<ll,ll>dp[2000050];
struct tree{
    ll l,r,minn=1e18,minsum=0;
}tr[4000050];
void build(ll p,ll l,ll r){
    tr[p].l=l,tr[p].r=r;
    if(l==r){
        tr[p].minn=1e18,tr[p].minsum=0;
        return ;
    }
    ll mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void pushup(ll p){
    if(tr[p<<1].minn<tr[p<<1|1].minn){
        tr[p].minn=tr[p<<1].minn;
        tr[p].minsum=tr[p<<1].minsum;
    }else if(tr[p<<1].minn>tr[p<<1|1].minn){
        tr[p].minn=tr[p<<1|1].minn;
        tr[p].minsum=tr[p<<1|1].minsum;
    }else{
        tr[p].minn=tr[p<<1].minn;
        tr[p].minsum=tr[p<<1].minsum+tr[p<<1|1].minsum;
    }
}
void update(ll p,ll x,ll k,ll l){
    if(tr[p].l==tr[p].r){
        tr[p].minn=k,tr[p].minsum=l;
        return ;
    }
    ll mid=(tr[p].l+tr[p].r)>>1;
    if(x<=mid)update(p<<1,x,k,l);
    else update(p<<1|1,x,k,l);
    pushup(p);
}
tree query(ll p,ll l,ll r){
    if(l<=tr[p].l&& tr[p].r<=r){
        return tr[p];
    }
    ll mid=(tr[p].l+tr[p].r)>>1;
    if(l>mid)return query(p<<1|1,l,r);
    else if(r<=mid)return query(p<<1,l,r);
    else {
        tree x=query(p<<1,l,r),y=query(p<<1|1,l,r);
        tree ans;
        ans.l=x.l,ans.r=y.r;
        if(x.minn<y.minn){
            ans.minn=x.minn;
            ans.minsum=x.minsum;
        }else if(x.minn>y.minn){
            ans.minn=y.minn;
            ans.minsum=y.minsum;
        }else{
            ans.minn=x.minn;
            ans.minsum=x.minsum+y.minsum;
        }
        return ans;
    }
}
ll n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d; 
        for(ll i=1;i<=n;i++)cin>>x[i];
        if(c==11 || c==12){
            ll k=d/(x[2]-x[1]);
            if(k==1)cout<<0<<endl;
            else {
                cout<<n-2*k+1<<endl;
            }
        }else{
            for(ll i=1;i<=n;i++){
                pl[i]=lower_bound(x+1,x+i,x[i]-d)-x;
            }
            ll ans=0;
            for(ll i=1;i<=n;i++){
                build(1,1,n);
                update(1,i,0,1);
                // cout<<i<<":"<<endl;
                // cout<<i<<" 0 1"<<endl;
                for(ll j=i+1;j<=n;j++){
                    tree p=query(1ll,max(i,pl[j]),j);
                    // cout<<j<<" "<<p.minn+1<<" "<<p.minsum<<endl;
                    if(p.minsum==2)ans++;
                    update(1,j,p.minn+1,p.minsum);
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}