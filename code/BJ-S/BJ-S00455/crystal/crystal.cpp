#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define rc ((u<<1)+1)
#define lc (u<<1)
using namespace std;
long long n,m,w[2000005],a[500005];
void build(int u,int l,int r){
    if(l==r){
        w[u]=a[l];
        return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    w[u]=max(w[lc],w[rc]);
    //cout<<u<<' '<<l<<' '<<r<<' '<<w[u]<<' '<<lc<<' '<<rc<<'\n';
}
long long query(int u,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr){
        //cout<<"case 1:"<<u<<' '<<l<<' '<<r<<' '<<w[u]<<' '<<ql<<' '<<qr<<'\n';
        return w[u];
    }
    else if(r<ql||l>qr){
        //cout<<"case 2:"<<u<<' '<<l<<' '<<r<<' '<<w[u]<<' '<<ql<<' '<<qr<<'\n';
        return 0x8f8f8f8f8f8f8f8f;
    }
    else{
        //cout<<"case 3:"<<u<<' '<<l<<' '<<r<<' '<<w[u]<<' '<<ql<<' '<<qr<<'\n';
        return max(query(lc,l,mid,ql,qr),query(rc,mid+1,r,ql,qr));
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    memset(w,0x8f,sizeof w);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    build(1,1,n);
    long long l=1,r=1,mx=a[1],ans=1,sm=0,zt=1;
    while(r<=n){
        if(zt==1){
            //cout<<zt<<':'<<l<<' '<<r<<' ';
            r++;
            int p=query(1,1,n,l,r);
            //cout<<mx<<' '<<ans<<' '<<sm<<' '<<p<<" -> ";
            if(p-mx>0&&sm+(r-l)*(p-mx)<=m){
                sm=sm+(r-l)*(p-mx);
                ans=max(ans,r-l+1);
                mx=p;
            }
            else if(mx>=a[r]&&sm+mx-a[r]<=m){
                sm=sm+mx-a[r];
                ans=max(ans,r-l+1);
            }
            else if(mx>=a[r]){
                sm=sm+mx-a[r];
                zt=0;
            }
            else{
                sm=sm+(r-l)*(p-mx);
                mx=p;
                zt=0;
            }
            //cout<<zt<<':'<<l<<' '<<r<<' ';
            //cout<<mx<<' '<<ans<<' '<<sm<<' '<<p<<"\n";
        }
        if(zt==0){
            //cout<<zt<<':'<<l<<' '<<r<<' ';
            l++;
            int p=query(1,1,n,l,r);
            //cout<<mx<<' '<<ans<<' '<<sm<<' '<<p<<" -> ";
            if(mx>p&&sm-(mx-p)*(r-l+1)<=m){
                sm=sm-(mx-p)*(r-l+1);
                ans=max(ans,r-l+1);
                mx=p;
                zt=1;
            }
            else if(mx<=p&&sm-(mx-a[l-1])<=m){
                sm=sm-(mx-a[l-1]);
                ans=max(ans,r-l+1);
                zt=1;
            }
            else if(mx>p){
                sm=sm-(mx-p)*(r-l+1);
                mx=p;
            }
            else{
                sm=sm-(mx-a[l-1]);
            }
            //cout<<zt<<':'<<l<<' '<<r<<' ';
            //cout<<mx<<' '<<ans<<' '<<sm<<' '<<p<<"\n";
        }
    }
    cout<<ans;
    return 0;
}
