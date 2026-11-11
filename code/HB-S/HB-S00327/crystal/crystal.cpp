#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m,Ans,S,idx,a[N];
int tree[N*4],tag[N*4];
void pushup(int u)
{
    tree[u]=tree[u*2]+tree[u*2+1];
}
void maketag(int u,int len,int x)
{
    tree[u]+=len*x;
    tag[u]+=x;
}
void pushdown(int u,int l,int r)
{
    int mid=(l+r)/2;
    maketag(u*2,mid-l+1,tag[u]);
    maketag(u*2+1,r-mid,tag[u]);
    tag[u]=0;
}
void Fix(int u,int l,int r,int ql,int qr,int k)
{
    if(ql<=l&&r<=qr) maketag(u,r-l+1,k);
    else if(qr<l||r<ql) return;
    else
    {
        int mid=(l+r)/2;
        pushdown(u,l,r);
        Fix(u*2,l,mid,ql,qr,k);
        Fix(u*2+1,mid+1,r,ql,qr,k);
        pushup(u);
    }
}
int Find(int u,int l,int r,int ql,int qr)
{
    if(ql<=l&&r<=qr) return tree[u];
    else if(qr<l||r<ql) return 0LL;
    else
    {
        int mid=(l+r)/2;
        pushdown(u,l,r);
        return Find(u*2,l,mid,ql,qr)+Find(u*2+1,mid+1,r,ql,qr);
    }
}
int Query(int u,int l,int r,int ql,int qr,int k)
{
    if(qr<l||r<ql) return 0;
    if(l==r) return l;
    int mid=(l+r)/2;
    pushdown(u,l,r);
    if(tree[u*2]>=k) return Query(u*2,l,mid,ql,qr,k);
    else return Query(u*2+1,mid+1,r,ql,qr,k-tree[u*2]);
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        Fix(1,1,n,1,i-1,a[i]-a[i-1]);
        S=Find(1,1,n,1,i-1),idx=Query(1,1,n,1,i-1,S-m);
        Ans=max(Ans,i-idx);
    }
    cout<<Ans;
}
