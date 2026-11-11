#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans;
int a[N];
struct node{
    int sum,tag;
}tr[N<<2];
void pushup(int now){
    tr[now].sum=tr[now*2].sum+tr[now*2+1].sum;
}
void pushdown(int now,int l,int r){
    if(tr[now].tag){
        int mid=l+r>>1;
        tr[now*2].sum+=tr[now].tag*(mid-l+1);
        tr[now*2].tag+=tr[now].tag;
        tr[now*2+1].sum+=tr[now].tag*(r-mid);
        tr[now*2+1].tag+=tr[now].tag;
        tr[now].tag=0;
    }
}
void modify(int now,int l,int r,int ql,int qr,int k){
    if(ql<=l&&r<=qr){
        tr[now].sum+=(r-l+1)*k;
        tr[now].tag+=k;
        return;
    }
    int mid=l+r>>1;
    pushdown(now,l,r);
    if(ql<=mid) modify(now*2,l,mid,ql,qr,k);
    if(qr>mid) modify(now*2+1,mid+1,r,ql,qr,k);
    pushup(now);
}
int query(int now,int l,int r,int ql,int qr,int k){
    //cout<<now<<" "<<l<<" "<<r<<' '<<k<<"\n";
    if(l==r) return tr[now].sum>k?l+1:l;
    int mid=l+r>>1;
    pushdown(now,l,r);
    if(tr[now*2+1].sum>=k) return query(now*2+1,mid+1,r,ql,qr,k);
    else return query(now*2,l,mid,ql,qr,k-tr[now*2+1].sum);
}
int query2(int now,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr) return tr[now].sum;
    int mid=l+r>>1,res=0;
    pushdown(now,l,r);
    if(ql<=mid) res+=query2(now*2,l,mid,ql,qr);
    if(qr>mid) res+=query2(now*2+1,mid+1,r,ql,qr);
    return res;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    modify(1,1,n,1,1,a[2]-a[1]);
    ans=1;
    for(int i=2;i<=n;++i){
        int res=query(1,1,n,1,i,m);
        ans=max(ans,i-res+1);
        modify(1,1,n,1,i,a[i+1]-a[i]);
    }
    cout<<ans<<"\n";
    return 0;
}
