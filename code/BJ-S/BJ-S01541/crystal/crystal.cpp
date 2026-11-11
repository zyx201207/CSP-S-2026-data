#include<iostream>
#include<algorithm>
using namespace std;
constexpr int N=5e5+5;
using ll=long long;
ll a[N],m;
int n;
ll tree[N<<2],tag[N<<2];
#define ls p<<1
#define rs p<<1|1
void pushdown(int p,int l,int r){
    if(tag[p]){
        int m=(l+r)>>1;
        tree[ls]+=tag[p]*(m-l+1);
        tree[rs]+=tag[p]*(r-m);
        tag[ls]+=tag[p];
        tag[rs]+=tag[p];
        tag[p]=0;
    }
}
void add(int p,int l,int r,int x,int y,ll k){
    if(x<=l&&r<=y){
        tree[p]+=k*(r-l+1);
        tag[p]+=k;
        return;
    }
    pushdown(p,l,r);
    int m=(l+r)>>1;
    if(x<=m) add(ls,l,m,x,y,k);
    if(y>m) add(rs,m+1,r,x,y,k);
    tree[p]=tree[ls]+tree[rs];
}
// int query(int p,int l,int r){
//     if(l==r) return l;
//     pushdown(p,l,r);
//     int mid=(l+r)>>1;
//     if(tree[rs]>=m) return query(rs,mid+1,r);
//     return query(ls,l,mid);
// }
ll getsum(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y) return tree[p];
    pushdown(p,l,r);
    int m=(l+r)>>1;
    ll ret=0;
    if(x<=m) ret+=getsum(ls,l,m,x,y);
    if(y>m) ret+=getsum(rs,m+1,r,x,y);
    return ret;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=1;
    for(int l=1,r=2;r<=n;r++){
        add(1,1,n,1,r-1,a[r]-a[r-1]);
        while(l<r&&getsum(1,1,n,l,r)>m) l++;
        ans=max(ans,r-l+1);
        // cout<<r<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
}