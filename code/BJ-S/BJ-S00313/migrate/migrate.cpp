#include<iostream>
#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
using namespace std;

const int MAXN=2e6+5;
int c,t,n,d,x[MAXN],tr[MAXN<<2],cnt[MAXN<<2];

void recover(int x){
    if(tr[lc]<tr[rc])tr[x]=tr[lc],cnt[x]=cnt[lc];
    if(tr[lc]>tr[rc])tr[x]=tr[rc],cnt[x]=cnt[rc];
    if(tr[lc]==tr[rc])tr[x]=tr[lc],cnt[x]=cnt[lc]+cnt[rc];
}
void build(int x,int l,int r){
    if(l==r){
        tr[x]=9e18,cnt[x]=0;
        return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    recover(x);
}
void update(int x,int l,int r,int p,int k,int ct){
    if(p<=l&&r<=p){
        tr[x]=k,cnt[x]=ct;
        return;
    }
    if(p<=mid)update(lc,l,mid,p,k,ct);
    if(p>mid)update(rc,mid+1,r,p,k,ct);
    recover(x);
}
pair<int,int> calc(int x,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr)return {tr[x],cnt[x]};
    pair<int,int>res={9e18,0};
    if(ql<=mid){
        pair<int,int>nw=calc(lc,l,mid,ql,qr);
        if(nw.first<res.first)res=nw;
        else if(nw.first==res.first)res.second+=nw.second;
    }
    if(qr>mid){
        pair<int,int>nw=calc(rc,mid+1,r,ql,qr);
        if(nw.first<res.first)res=nw;
        else if(nw.first==res.first)res.second+=nw.second;
    }
    return res;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        int ans=0;
        for(int i=1;i<n;i++){
            build(1,i,n);
            update(1,i,n,i,0,1);
            for(int j=i+1;j<=n;j++){
                int l=i,r=j-1,aans=-1;
                while(l<=r){
                    int md=l+r>>1;
                    if(x[j]-x[md]<=d)aans=md,r=md-1;
                    else l=md+1;
                }
                if(aans==-1)break;
                pair<int,int>res=calc(1,i,n,aans,j-1);
                if(res.second==2)ans++;
                update(1,i,n,j,res.first+1,res.second);
                // cout<<i<<' '<<j<<'('<<res.first<<','<<res.second<<')'<<'-'<<aans<<endl;
                // for(int j=i;j<=n;j++)
                //     cout<<'('<<calc(1,i,n,j,j).first<<','<<calc(1,i,n,j,j).second<<')'<<' ';
                // cout<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}