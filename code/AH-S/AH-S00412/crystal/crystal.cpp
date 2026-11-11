#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long a[1000050],s[1000050],k;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<=r){
            int m=(l+r)>>1;
            long long len=(i-m+1);
            //cerr<<"#"<<" "<<l<<" "<<r<<" "<<i<<endl;
            if(a[i]*len-s[i]+s[m-1]<=k){
                r=m-1;
            }else{
                l=m+1;
            }
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
struct segmenttree{
    struct node{
        void down(){}
    };
    void pushup(int p){
    }
    void pushdown(int p){
    }
    void build(int p,int l,int r){
        if(l==r){

            return;
        }
        int m=(l+r)>>1;
        build(p<<1,l,m);
        build(p<<1|1,m+1,r);
        pushup(p);
    }
    void update(int p,int l,int r,int x,int y,int v){
        if(r<x||l>y)return;
        if(x<=l&&r<=y){
                t[p].down(v);
            return;
        }
        int m=(l+r)>>1;
        pushdown(p);
        update(p<<1,l,m,x,y,v);
        update(p<<1|1,m+1,r,x,y,v);
        pushup(p);
    }
    int query(int p,int l,int r,int x,int y){
        if(l>y||r<x)return [];
        if(x<=l&&r<=y)return t[p].s;
        int m=(l+r)>>1;
        pushdown(p);
        return
        query(p<<1,l,m,x,y)[]
        query(p<<1|1,m+1,r,x,y);
    }
};
struct ST{
    int f[21][];
    void init(int n,int*A){
        for(int i=1;i<=n;i++)f[0][i]=A[i];
        for(int i=1;i<=20;i++){
            for(int j=1;j+(1<<i)-1<=n;j++){
                int nxt=j+(1<<(i-1));
                f[i][j]=max(
                f[i-1][j],
                f[i-1][nxt]
                );
            }
        }
    }
    int query(int l,int r){
        int len=(r-l+1);
        int k=__lg(len);
        return max
        (f[k][l],f[k][r-(1<<k)+1]);
    }
};
*/
