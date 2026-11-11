#include <bits/stdc++.h>
#define N 2000002
#define fi first
#define se second
#define ls (p<<1)
#define rs (p<<1|1)
#define ll long long
using namespace std;
ll n,d,x[N],pre[N],f[N],ans,c,T;
struct node{int l,r;ll mn,cnt;}t[N<<2];
void pushup(int p){
    if(t[ls].mn<t[rs].mn)  t[p].mn=t[ls].mn,t[p].cnt=t[ls].cnt;
    else if(t[ls].mn>t[rs].mn)  t[p].mn=t[rs].mn,t[p].cnt=t[rs].cnt;
    else t[p].mn=t[ls].mn,t[p].cnt=t[ls].cnt+t[rs].cnt;
}
void build(int p,int l,int r){
    t[p].l=l,t[p].r=r,t[p].cnt=1;
    if(l==r)  return;
    int mid=(l+r)>>1;
    build(ls,l,mid),build(rs,mid+1,r);
    pushup(p);
}
void upd(int p,int x,int d){
    if(t[p].l==t[p].r)  return t[p].mn=d,void();
    int mid=(t[p].l+t[p].r)>>1;
    if(x<=mid)  upd(ls,x,d);
    else  upd(rs,x,d);
    pushup(p);
}
pair<ll,ll> query(int p,int l,int r){
    if(t[p].l>=l&&t[p].r<=r)  return {t[p].mn,t[p].cnt};
    int mid=(t[p].l+t[p].r)>>1;
    if(r<=mid)  return query(ls,l,r);
    else if(l>mid)  return query(rs,l,r);
    else{
        pair<ll,ll> resl=query(ls,l,r),resr=query(rs,l,r);
        if(resl.fi<resr.fi)  return resl;
        else if(resl.fi>resr.fi)  return resr;
        else  return {resl.fi,resl.se+resr.se};
    }
}
void init(){
    for(int i=1;i<=n;i++)  pre[i]=f[i]=0;
    ans=0;
}
void solve(){
    cin>>n>>d;
    init();
    build(1,1,n);
    for(int i=1;i<=n;i++)  cin>>x[i];
    for(int i=1,l=1;i<=n;i++){
        while(x[i]-x[l]>d&&l<=i)  l++;
        pre[i]=l;
    }
    for(ll u=1;u<=n;u++){
        f[u]=0;upd(1,u,f[u]);
        for(ll v=u+1;v<=n;v++){
            if(pre[v]<v){
                auto t=query(1,max(u,pre[v]),v-1);
                f[v]=t.fi+1;
                if(t.se==2)  ans++;
                upd(1,v,f[v]);
            }else  break;
        }
        // for(int v=1;v<=n;v++)  upd(1,v,0);
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>T;
    while(T--)  solve();
    return 0;
}
/*
#include <bits/stdc++.h>
#define N 2000002
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
ll n,d,x[N],f[N],g[N],flg[N],c,T,ans;int pre[N],lst[N];
void init(){
    ;
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)  cin>>x[i];
    for(int i=n,r=n;i>=1;i--){
        while(x[r]-x[i]>d&&r>=i)  r--;
        lst[i]=r;
    }
    for(int i=1,l=1;i<=n;i++){
        while(x[i]-x[l]>d&&l<=i)  l++;
        pre[i]=l;
    }
    f[n]=flg[n]=1;
    for(int i=n-1;i>=1;i--){
        if(lst[i-1]+1==i)  flg[i]=1;
        if(lst[i-1]+1<=lst[i])  f[i]=f[lst[i]]+(lst[i]-lst[i-1])-flg[i+1];
        else  f[i]=f[lst[i]];
    }
    for(int i=1;i<=n;i++)  flg[i]=0;
    g[1]=flg[1]=1;
    for(int i=2;i<=n;i++){
        if(pre[i+1]-1==i)  flg[i]=1;
        if(pre[i]<=pre[i+1]-1)  g[i]=g[pre[i]]+(pre[i+1]-pre[i])-flg[i-1];
        else  g[i]=g[pre[i]];
    }
    // for(int i=1;i<=n;i++)  cout<<f[i]<<" ";
    // cout<<"\n";
    // for(int i=1;i<=n;i++)  cout<<g[i]<<" ";
    // cout<<"\n";
    for(int u=1;u<=n;u++){
        int y=lst[u],x=y-1;
        if(lst[x]!=lst[y]||x<=u)  continue;
        int v=lst[x];
        if(y>=v)  continue;
        cout<<u<<" "<<x<<" "<<y<<" "<<v<<"\n";
        ans+=1ll*g[u]*f[v];
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin>>c>>T;
    while(T--)  solve();
    return 0;
}
*/