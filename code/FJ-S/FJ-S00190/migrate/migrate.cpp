#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll rd(){
    char ch=getchar();
    ll f=1,x=0;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-48;
        ch=getchar();
    }
    return x*f;
}
#define P pair<ll,ll> 
#define se second
#define fi first
const ll N_ = 5e3+10;
ll ans,node,ls[N_*4],rs[N_*4],dp[N_],g[N_],N,D,T,C,a[N_],pre[N_],root;
P t[N_*4];
inline void push_up(ll k){
    if(!ls[k])return t[k]=t[rs[k]],void();
    if(!rs[k])return t[k]=t[ls[k]],void();
    if(t[ls[k]].fi==t[rs[k]].fi){
        t[k]={t[ls[k]].fi,t[ls[k]].se+t[rs[k]].se};
        return ;
    }
    if(t[rs[k]].fi>t[ls[k]].fi)t[k]=t[ls[k]];
    if(t[ls[k]].fi>t[rs[k]].fi)t[k]=t[rs[k]];
}
P ask(ll k,ll l,ll r,ll p,ll q){
    if(!k)return {0x3f3f3f3f3f3f3f3f,0};
    if(p<=l&&r<=q){
        return t[k];
    }
    ll mid=l+r>>1;
    P res={0x3f3f3f3f3f3f3f,0};
    if(p<=mid)res=ask(ls[k],l,mid,p,q);
    if(q>mid){
        P o=ask(rs[k],mid+1,r,p,q);
        if(res.fi>o.fi)res=o;
        else {
            if(res.fi==o.fi)res.se+=o.se;
        }
    }
    return res;
}
void add(ll& k,ll l,ll r,ll p,P x){
    if(!k)k=++node,t[k]={0x3f3f3f3f3f3f3f3f,0};
    if(l==r)return t[k]=x,void();
    ll mid=l+r>>1;
    if(p<=mid)add(ls[k],l,mid,p,x);
    else add(rs[k],mid+1,r,p,x);
    push_up(k);
}
void solve(ll k)
{
    for(int i=k;i<=N;i++)dp[i]=0x3f3f3f3f3f3f3f3f,g[i]=0;
    for(int i=0;i<=node;i++)t[i]={0x3f3f3f3f3f3f3f3f,0},ls[i]=0,rs[i]=0;
    root=0;node=0;
    add(root,1,N,k,{0,1});
    dp[k]=0;
    g[k]=1;
    for(int i=k+1;i<=N;i++)
    {
        if(max(pre[i],k)<=i-1)
        {
            P x=ask(root,1,N,max(pre[i],k),i-1);
            dp[i]=x.fi+1;g[i]=x.se;
            // add(root,1,N,i,dp[i]);
        }
        else break;
        add(root,1,N,i,{dp[i],g[i]});
    }
    // for(int i=1;i<=N;i++)
    // cout<<k<<"\n==========\n";
    // for(int i=k;i<=N;i++)printf("dp[%d]=%lld,g[%d]=%lld\n",i,dp[i],i,g[i]);
    for(int i=k;i<=N;i++)if(g[i]==2)ans++;
}
inline void work(){
    N=rd();D=rd();
    for(int i=1;i<=N;i++)a[i]=rd();
    pre[1]=1;
    for(int i=2,l=1;i<=N;i++){
        while(a[i]-a[l]>D)l++;
        pre[i]=l;   
    }
    for(int k=1;k<=N;k++)
    {
        // cout<<"\n=======\n"<<k<<"\n======\n";
        solve(k);
        // ans=0;
    }
    // cout<<endl;
    cout<<ans<<'\n';
}
inline void clear(){
    ans=0;return ;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    C=rd();T=rd();
    while(T--){
        work();
        clear();
    }
    return 0;
}
//Oct31==Dec25?