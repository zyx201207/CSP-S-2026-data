#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll rd(){ll x=0,fh=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-') fh=-1;ch=getchar();}while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x*fh;}
const int N=5e5+10;
int n,nn,ans,c[N];
ll m,a[N],ls[N],ned;
struct node{
    ll sum;int cnt;

    friend node operator+(const node &x,const node &y){return {x.sum+y.sum,x.cnt+y.cnt};}
}s[N<<2];
ll tag[N<<2];

void built(int k,int l,int r){
    if(l==r){
        s[k].cnt=c[l];
        return;
    }
    int mid=l+r>>1;
    built(k<<1,l,mid),built(k<<1|1,mid+1,r);
    s[k]=s[k<<1]+s[k<<1|1];
}

void calc(int k,ll v){
    tag[k]+=v;
    s[k].sum+=v*s[k].cnt;
}

void pushdown(int k){
    if(!tag[k]) return;
    calc(k<<1,tag[k]),calc(k<<1|1,tag[k]);
    tag[k]=0;
}

void change(int k,int l,int r,int x,int y,ll v){
    if(x<=l&&r<=y) return calc(k,v);
    pushdown(k);
    int mid=l+r>>1;
    if(x<=mid) change(k<<1,l,mid,x,y,v);
    if(y>mid) change(k<<1|1,mid+1,r,x,y,v);
    s[k]=s[k<<1]+s[k<<1|1];
}

node findp(int k,int l,int r,ll v){
    if(v<ned-ls[r]) return {0ll,0};
    if(s[k].sum<=v){
        return s[k];
    }
    if(l==r){
        ll h=v/(ned-ls[l]);
        return {h*(ned-ls[l]),h};
    }
    pushdown(k);
    int mid=l+r>>1;
    node ans=findp(k<<1|1,mid+1,r,v);
    node res=findp(k<<1,l,mid,v-ans.sum);
    return ans+res;
}

node ask(int k,int l,int r,int x,ll v){
    if(l>x||v<ned-ls[r]) return {0ll,0};
    if(r<=x) return findp(k,l,r,v);
    pushdown(k);
    int mid=l+r>>1;
    node ans=ask(k<<1|1,mid+1,r,x,v);
    node res=ask(k<<1,l,mid,x,v-ans.sum);
    return ans+res;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=rd(),m=rd();
    for(int i=1;i<=n;i++) a[i]=rd(),ls[i]=a[i];
    sort(ls+1,ls+n+1);
    nn=unique(ls+1,ls+n+1)-ls-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(ls+1,ls+nn+1,a[i])-ls,c[a[i]]++;
    built(1,1,nn);
    for(int i=1;i<=nn;i++){
        ned=ls[i];
        if(i>1) change(1,1,nn,1,i-1,ls[i]-ls[i-1]);
        ans=max(ans,ask(1,1,nn,i,m).cnt);
    }
    printf("%d",ans);
    return 0;
}