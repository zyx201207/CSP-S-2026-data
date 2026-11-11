#include<bits/stdc++.h>
using namespace std;

using LL=__int128;
const int MAXN=5e5+10;

long long n,m,a[MAXN];

LL val[MAXN<<2],lazy[MAXN<<2];
void pushdown(int w,int l,int r){
    LL &laz=lazy[w];
    if(laz==0)return;
    int mid=l+r>>1;
    val[w<<1]+=laz*(mid-l+1);
    lazy[w<<1]+=laz;
    val[w<<1|1]+=laz*(r-mid);
    lazy[w<<1|1]+=laz;
    laz=0;
}
void add(int w,int l,int r,int L,int R,int v){
    if(l>R||L>r)return ;
    if(L<=l&& r<=R){
        val[w]+=(r-l+1)*v;
        lazy[w]+=v;
        return ;
    }
    int mid=l+r>>1;
    pushdown(w,l,r);
    add(w<<1,l,mid,L,R,v);
    add(w<<1|1,mid+1,r,L,R,v);
}
LL srch(int w,int l,int r,int pos){
    if(l>pos||pos>r)return 0;
    if(l==r&&l==pos){
        return val[w];
    }
    int mid=l+r>>1;
    pushdown(w,l,r);
    return srch(w<<1,l,mid,pos)+srch(w<<1|1,mid+1,r,pos);
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];

    sort(a+1,a+n+1);

    int l=1,r=0,ans=0;
    LL lval=0;
    while(r<=n){
        ++r;
        LL del=a[r]-a[r-1];


        add(1,1,n,l,l,(r-l+1)*del);
        if(l+1<=r)add(1,1,n,l+1,r,-del);

        lval+=(r-l)*del;
        while(l<r&&lval>m){
            ++l;
            lval+=srch(1,1,n,l);
        }

        ans=max(ans,r-l+1);
    }

    cout<<ans;

    return 0;
}
