#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=300005;
int n,m;
int lis[N];
int tr[N*4],lz[N*4];
void up(int u){
    tr[u]=max(tr[u*2],tr[u*2+1]);
}
void pushdown(int u){
    tr[u*2]=max(tr[u*2],lz[u]);
    tr[u*2+1]=max(tr[u*2+1],lz[u]);
    lz[u*2]=max(lz[u*2],lz[u]);
    lz[u*2+1]=max(lz[u*2+1],lz[u]);
    lz[u]=0;
}
void revise(int u,int l,int r,int x,int y,int p){
    if(x<=l&&r<=y){
        tr[u]=max(tr[u],p);
        lz[u]=max(lz[u],p);
        return;
    }
    pushdown(u);
    int mid=(l+r)>>1;
    if(x<=mid) revise(u*2,l,mid,x,y,p);
    if(y>=mid+1) revise(u*2+1,mid+1,r,x,y,p);
    up(u);
}
int site[N];
struct nod{
    int l,r;
    bool friend operator <(const nod &a,const nod &b){
        if(a.l==b.l) return a.r>b.r;
        return a.l<b.l;
    }
}tmp;
priority_queue<nod>qu[M];
void query(int u,int l,int r,int pos){
    if(l==r){
        tmp.l=tr[u]+1;
        tmp.r=pos;
        qu[lis[pos]].push(tmp);
        return;
    }
    pushdown(u);
    int mid=(l+r)>>1;
    if(pos<=mid) query(u*2,l,mid,pos);
    if(pos>=mid+1) query(u*2+1,mid+1,r,pos);
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&lis[i]);
        if(site[lis[i]]>0){
            revise(1,1,n,site[lis[i]],i-1,site[lis[i]]);
        }
        site[lis[i]]=i;
    }
    for(int i=1;i<=n;i++){
        query(1,1,n,i);
    }
    for(int i=1;i<=m;i++){
        int len=qu[i].size(),cnt=0;
        if(len==0) continue;
        int ll=qu[i].top().l,rr=qu[i].top().r;
        qu[i].pop();
        cnt+=rr-ll+1;
        for(;!qu[i].empty();){
            for(;!qu[i].empty()&&qu[i].top().r<=rr;qu[i].pop());
            if(qu[i].top().l<=rr){
                cnt+=qu[i].top().r-rr+1;
                ll=qu[i].top().l;
                rr=qu[i].top().r;
            }
            else{
                cnt+=qu[i].top().r-qu[i].top().l+1;
                ll=qu[i].top().l;
                rr=qu[i].top().r;
            }
            qu[i].pop();
        }
        printf("%d ",cnt);
    }
    return 0;
}
