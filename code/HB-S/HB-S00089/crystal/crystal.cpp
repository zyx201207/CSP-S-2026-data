#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],ans=1;
struct SGT{
    int tr[N<<2],tag[N<<2];
    void down(int l,int r,int p){
        if(!tag[p]) return;
        int mid=(l+r)>>1;
        tr[p<<1]+=(mid-l+1)*tag[p];
        tag[p<<1]+=tag[p];
        tr[p<<1|1]+=(r-mid)*tag[p];
        tag[p<<1|1]+=tag[p];
        tag[p]=0;
    }
    void update(int p,int l,int r,int ql,int qr,int x){
        if(ql<=l&&r<=qr){
            tag[p]+=x;
            tr[p]+=(r-l+1)*x;
            return;
        }
        down(l,r,p);
        int mid=(l+r)>>1;
        if(ql<=mid) update(p<<1,l,mid,ql,qr,x);
        if(qr>mid) update(p<<1|1,mid+1,r,ql,qr,x);
        tr[p]=tr[p<<1]+tr[p<<1|1];
    }
    int query(int p,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr) return tr[p];
        down(l,r,p);
        int mid=(l+r)>>1,res=0;
        if(ql<=mid) res+=query(p<<1,l,mid,ql,qr);
        if(qr>mid) res+=query(p<<1|1,mid+1,r,ql,qr);
        return res;
    }
}sgt;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        sgt.update(1,1,n,1,i-1,a[i]-a[i-1]);
        int l=1,r=i-1,res=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(sgt.query(1,1,n,mid,i-1)<=m) res=mid,r=mid-1;
            else l=mid+1;
        }
        if(res!=0) ans=max(ans,i-res+1);
    }
    cout<<ans;
    return 0;
}
